#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &object)
{
    *this = object;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {}
    return (*this);
}
PmergeMe::~PmergeMe()
{
}
//_________________________________________________________________________

// Merge two subarrays of 'arr',[left..mid], [mid+1..right].
void PmergeMe::merge(std::deque<int>& arr, int left, int mid, int right)
{
    // Calculate the sizes of the two subarrays.
	int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create two temporary deques 'L' and 'R' to hold the subarrays.
    std::deque<int> L;
    std::deque<int> R;

    // Copy data to 'L' and 'R' from 'arr'.
    for (int i = 0; i < n1; i++) {
        L.push_back(arr[left + i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(arr[mid + 1 + i]);
    }
	// Initialize the index for merging back into 'arr'
    int k = left;

    // Merge the two subarrays into 'arr'.
    while (!L.empty() && !R.empty())
	{
        if (L.front() <= R.front())
		{
            arr[k++] = L.front();// Take the smaller element from 'L' and place it in 'arr'.
            L.pop_front();// Remove the element from 'L'.
        }
		else{
            arr[k++] = R.front();
            R.pop_front();
        }
    }

    // Copy any remaining elements from 'L' and 'R' to 'arr'.
    while (!L.empty()) {
        arr[k++] = L.front();
        L.pop_front();
    }
    while (!R.empty()) {
        arr[k++] = R.front();
        R.pop_front();
    }
}
//__________________________________________________________________________
void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L;
    std::vector<int> R;

    for (int i = 0; i < n1; i++) {
        L.push_back(arr[left + i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(arr[mid + 1 + i]);
    }

    int k = left;
    while (!L.empty() && !R.empty())
	{
        if (L.front() <= R.front())
		{
            arr[k++] = L.front();
            L.pop_back();
        }
		else
		{
            arr[k++] = R.front();
            R.pop_back();
        }
    }
    while (!L.empty()) {
        arr[k++] = L.front();
        L.pop_back();
    }
    while (!R.empty()) {
        arr[k++] = R.front();
        R.pop_back();
    }
}
//_________________________________________________________________________

void  PmergeMe::insertionVecDeque(std::deque<int>& arr, int left, int right)
{
    if (left < right) // run till we have in the lift and right 1 number
    {
		int mid = left + (right - left) / 2;
		insertionVecDeque(arr, left, mid);
		insertionVecDeque(arr, mid + 1, right);
		// Create a temp deque containing the elements within the specified range.
		std::deque<int> temp(arr.begin() + left, arr.begin() + right + 1); 
		// Merge the two sorted halves in 'temp' back into 'arr'.
		merge(temp, 0, mid - left, right - left); 
		// Copy the sorted values from 'temp' back into the original 'arr'
		copy(temp.begin(), temp.end(), arr.begin() + left); 
    }
}
//_________________________________________________________________________

void  PmergeMe::insertionVecDeque(std::vector<int>& arr, int left, int right)
{
    if (left < right) // run till we have in the lift and right 1 number
    {
		int mid = left + (right - left) / 2;
		insertionVecDeque(arr, left, mid);
		insertionVecDeque(arr, mid + 1, right);

		std::vector<int> temp(arr.begin() + left, arr.begin() + right + 1);
		merge(temp, 0, mid - left, right - left);
		copy(temp.begin(), temp.end(), arr.begin() + left);
    }
}
//_________________________________________________________________________

void  PmergeMe::insertionVec(std::deque<int>& arr)
{
	// Copy the vector 'arr' into a temporary deque 'temp'
    std::deque<int> temp(arr.begin(), arr.end());

    insertionVecDeque(temp, 0, temp.size() - 1);
    copy(temp.begin(), temp.end(), arr.begin());
}
//_________________________________________________________________________
void  PmergeMe::insertionList(std::vector<int>& arr)
{
    insertionVecDeque(arr, 0, arr.size() - 1);
    copy(arr.begin(), arr.end(), arr.begin());
}