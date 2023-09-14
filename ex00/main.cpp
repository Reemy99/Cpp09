#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2){
        BitcoinExchange B;
        B.readFile();
        B.calculate(av[1]);
    }
    else{
        std::cout << "Usage: ./btc <file>" << ac << std::endl;
        return 1;
    }
    return(0);
}