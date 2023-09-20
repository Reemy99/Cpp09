#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    PmergeMe p;
    if (argc <= 2) {
        std::cout << "Usage: PmergeMe <positive_integer_sequence>" << std::endl;
        return 1;
    }
    int i = 1;
    while (i < argc) {
        std::string str(argv[i]);
        if (str.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Usage: PmergeMe <positive_integer_sequence>" << std::endl;
            return 1;
        }
        i++;
    }
//=================deque======================

    std::deque<int> dequeInput;
    for (int i = 1; i < argc; i++) {
        dequeInput.push_back(atoi(argv[i]));
    }
    std::cout << "Before : ";
    for (size_t i = 0; i < dequeInput.size(); i++){
       std::cout << dequeInput[i] << " ";
    }
    std::cout << std::endl;

    std::deque<int> soretedDeque(dequeInput); // creates a copy of dequeInput in soretedDeque
    clock_t start = clock();   
    p.insertionVec(soretedDeque);      			// Sort the sequence using merge-insertion sort
    clock_t end = clock();

    double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6; // Convert to microseconds * 486

    std::cout << "\nAfter :";
    for (size_t i = 0; i < soretedDeque.size(); i++){
       std::cout << soretedDeque[i] << " ";
    }
    std::cout << "\nTime to process a range of " << dequeInput.size() << " elements with Vector Container : " << duration << " us" <<std::endl;
//=================vector======================

    std::vector<int> listInput;
    for (int i = 1; i < argc; i++) {
        listInput.push_back(atoi(argv[i]));
    }
    std::vector<int> sortedList(listInput);

    clock_t s = clock();
    p.insertionList(sortedList);
    clock_t d = clock();

    double time = (static_cast<double>(d - s) / CLOCKS_PER_SEC) * 1e6; // Convert to microseconds
    std::cout << "Time to process a range of  " << listInput.size() << " elements with List Container : " << time << " us" <<std::endl;
    return 0;
}
