#include "RPN.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2) {
            throw std::invalid_argument("Error: Invalid HERE input");
        }
        RPN rpn = RPN();
        std::cout << rpn.execute(argv[1]) << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}