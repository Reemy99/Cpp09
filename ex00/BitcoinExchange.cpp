#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;

}

BitcoinExchange::BitcoinExchange(std::string fileInfo)
{
    if (readFile())
		return ;
	if (!calculate(fileInfo))
		return ;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::readFile()
{
	std::string			date, price, line;
    std::ifstream       file("data.cvs");
    std::stringstream	str(line);

    if (file.fail()) {
        std::cerr << " Can't read the file " << std::endl;
        file.close();
        return(false);
    }

    getline(file, line);
    while (!file.eof())
    {
        getline(file, line);
        getline(str, date, ',');
        getline(str, price);
        this->_map[date] = atof(price.c_str()); // K = date AND V= price
    }
    file.close();
    return(true);
}

bool BitcoinExchange::checkValidYMD(std::string year, std::string month, std::string day)
{
    int	y = atoi(year.c_str());  
	int	m = atoi(month.c_str());
	int	d = atoi(day.c_str());

	if (y < 2009 || y > 2023)
		return (false);
	if (m < 1 || m > 12)
		return (false);
	if (d < 1 || d > 31)
		return (false);
	if ((m == 2 && d > 28) && (y != 2012 && y != 2016 && y != 2020))
		return (false);
	if ((m == 2 && d > 29) && (y == 2012 || y == 2016 || y == 2020))
		return (false);
	return (true);
}


void BitcoinExchange::printDate(std::string date, float value)
{
    float res;
    std::map<std::string, float>::iterator it = _map.lower_bound(date);
    if (it != _map.begin() || it == this->_map.end())
    {
        it--;
        res = value * it->second;
        std::cout << date << " => " << std::fixed << std::setprecision(2) << value;
		std::cout << " = " << res << std::endl;
        return;
    }
    else if (checkDate(date))
        printDate(date, value);
}
bool BitcoinExchange::checkDelim(std::string pos)
{
    	if (pos.find(" | ") != 10)
	{
		std::cout << "Invalid Delimiter" << std::endl;
		return (false);
	}
	return (true);
}
bool BitcoinExchange::checkDate(std::string date)
{
    std::stringstream   str(date);
    std::string         year, month, day;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        std::cout << "Bad Input" << std::endl;
        return false;
    }
    getline(str, year,'-');
    getline(str, month,'-');
    getline(str, day);

    int	y = atoi(year.c_str());  
	int	m = atoi(month.c_str());
	int	d = atoi(day.c_str());

    if (y < 2009 || y > 2023)
		return (false);
	if (m < 1 || m > 12)
		return (false);
	if (d < 1 || d > 31)
		return (false);
    if ((m == 4 || m == 6 ||m == 9 || m == 11 )&& d > 30)
        return (false);
	return (true);
}

float BitcoinExchange::checkValidValue(std::string value)
{
	float	val = atof(value.c_str());
	if (value.find("-") == 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (-1);
	}
	if (value.size() > 4 || val > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (-1);
	}
	return (val);
}
void	BitcoinExchange::parseDates(std::string line)
{
	std::stringstream	str(line);
	std::string			date, delim, value;
	float				val;

	str >> date >> delim >> value;

	val = checkValidValue(value);
	if (!(checkDate(date)) || !(checkDelim(line)) || val == -1)
		return ;
	printDate(date, val);
}

bool BitcoinExchange::calculate(std::string info)
{
    // std::stringstream infile(info.c_str()); // cannot close
    std::ifstream   infile(info.c_str());
    std::string     line;

    if (infile.fail())
    {
        std::cout << "Input file Error" << std::endl;
		infile.close();
        return(false);
    }
    getline (infile, line);
    if (line.compare("date | value") != 0)
    {
        std::cout << "Error: Invalid File Format" << std::endl;
		infile.close();
		return (false);        
    }
    else {
		while (getline(infile, line))
		{
			this->parseDates(line);
		}
    }
    infile.close();
	return (true);

}


