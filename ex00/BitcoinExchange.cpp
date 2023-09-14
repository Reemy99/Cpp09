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
//___________________________________________________________

bool BitcoinExchange::readFile()
{
	std::string			date, price, line;
    std::ifstream       file("data.csv");

    if (file.fail()) {
        std::cerr << RED << " Can't read the file " <<  RESET << std::endl;
        file.close();
        return(false);
    }

    getline(file, line);
    while (!file.eof())
    {
        getline(file, line);
        std::stringstream	str(line);
        getline(str, date, ',');
        getline(str, price);
        this->_map[date] = atof(price.c_str()); // K = date AND V= price
    }
    file.close();
    return(true);
}
//___________________________________________________________
bool BitcoinExchange::checkDelim(std::string pos)
{
    if (pos.find(" | ") != 10)
	{
		std::cout << RED << "Invalid Delimiter" << RESET << std::endl;
		return (false);
	}
	return (true);
}
//___________________________________________________________

bool BitcoinExchange::checkValidYMD(std::string year, std::string month, std::string day)
{
    int	y = atoi(year.c_str());  
	int	m = atoi(month.c_str());
	int	d = atoi(day.c_str());

	if (y < 2009 )
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
//___________________________________________________________

bool BitcoinExchange::checkDate(std::string date)
{
    std::stringstream   str(date);
    std::string         year, month, day;

    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        std::cout << RED << "Bad Input" << RESET << std::endl;
        return false;
    }
    getline(str, year,'-');
    getline(str, month,'-');
    getline(str, day);

    if (!this->checkValidYMD(year, month, day))
	{
		std::cout << RED << "Error: bad input => "<< RESET << date << std::endl;
		return (false);
	}
	return (true);
}
//___________________________________________________________

float BitcoinExchange::checkValidValue(std::string value)
{
	float	val = atof(value.c_str());
	if (value.find("-") != std::string::npos) // cannot read - if it was in the midlle, and cannot read ..
    {
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return (-1);
	}
    else if (value.find("..") != std::string::npos)
    {
        std::cout << RED << "Error: bad input" << RESET << std::endl;
        return (-1);
    }
	else if (val > 1000) {
		std::cout << RED << "Error: too large a number." << RESET << std::endl;
		return (-1);
	}

	return (val);
}
//___________________________________________________________

void BitcoinExchange::printDate(std::string date, float value)
{
    std::map<std::string, float>::iterator it = _map.find(date);
    if (it != _map.end())
    {
        float res = value * it->second;
        std::cout << YELLOW << date << " => " << std::fixed << std::setprecision(2) << value;
        std::cout << " = " << res << std::endl;
    }
    else
    {
        it = _map.lower_bound(date);
        if (it != _map.begin())
        {
            --it;
            float res = value * it->second;
            std::cout << BLUE << "Lower bound of " <<  RESET << date << " => " << std::fixed << std::setprecision(2) << value;
            std::cout << " = " << res << BLUE <<  " (based on " << RESET <<  it->first << ")" << std::endl;
        }
    }
}
//___________________________________________________________

void	BitcoinExchange::parseDates(std::string line)
{
	std::stringstream	str(line);
	std::string			date;
	std::string			delim;
	std::string			value;
	float				val;

	str >> date >> delim >> value;

	val = checkValidValue(value);
	if (!(checkDate(date)) || !(checkDelim(line)) || val == -1)
		return ;
	printDate(date, val);
}
//___________________________________________________________

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
    else{
		while (getline(infile, line))
		{
			this->parseDates(line);
		}
    }
    infile.close();
	return (true);
}