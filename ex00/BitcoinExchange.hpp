#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _map; // key is a string (representing a date) AND the value is a floating (price)
        // char                        *path;
    
    public:
        BitcoinExchange();
        BitcoinExchange(std::string fileInfo);
        BitcoinExchange(const BitcoinExchange &copy);
        ~BitcoinExchange();

        bool    readFile();
        bool    checkDate(std::string date);
        bool    checkDelim(std::string pos);
        bool    calculate(std::string info);
        void    parseDates(std::string line);
        float   checkValidValue(std::string value);
        void    printDate(std::string date, float value);
        bool    checkValidYMD(std::string year, std::string month, std::string day);
};

#endif