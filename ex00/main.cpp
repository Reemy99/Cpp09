#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2){
        BitcoinExchange B;
        B.calculate(av[1]);
    }

    else{
        std::cout << "Usage: " << ac << std::endl;
    }
    return(0);
}