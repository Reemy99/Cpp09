#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <list>

// using namespace std;

class PmergeMe
{
    public:
    PmergeMe();
    PmergeMe(const PmergeMe &object);
    PmergeMe &operator=(const PmergeMe &rhs);
    ~PmergeMe();
        
    void merge(std::deque<int>& arr, int left, int mid, int right);
    void  insertionVecDeque(std::deque<int>& arr, int left, int right);
    void  insertionVec(std::deque<int>& arr);

    void  insertionList(std::vector<int>& arr);
    void  insertionVecDeque(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);

};

#endif