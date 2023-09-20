#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge(deque<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    deque<int> L;
    deque<int> R;

    for (int i = 0; i < n1; i++) {
        L.push_back(arr[left + i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(arr[mid + 1 + i]);
    }

    int k = left;
    while (!L.empty() && !R.empty()) {
        if (L.front() <= R.front()) {
            arr[k++] = L.front();
            L.pop_front();
        } else {
            arr[k++] = R.front();
            R.pop_front();
        }
    }

    while (!L.empty()) {
        arr[k++] = L.front();
        L.pop_front();
    }

    while (!R.empty()) {
        arr[k++] = R.front();
        R.pop_front();
    }
}

void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortDeque(deque<int>& arr, int left, int right) // 
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void  insertionVecDeque(deque<int>& arr, int left, int right)
{
    if (left < right)
    {
        if (right - left < 10) {
            sortDeque(arr, left, right); // Switch to insertion sort for small sublists
        }
        else
        {
            int mid = left + (right - left) / 2;
            insertionVecDeque(arr, left, mid);
            insertionVecDeque(arr, mid + 1, right);
            deque<int> temp(arr.begin() + left, arr.begin() + right + 1);
            merge(temp, 0, mid - left, right - left);
            copy(temp.begin(), temp.end(), arr.begin() + left);
        }
    }
}

void  insertionVec(vector<int>& arr)
{
    deque<int> temp(arr.begin(), arr.end());
     insertionVecDeque(temp, 0, temp.size() - 1);
    copy(temp.begin(), temp.end(), arr.begin());
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Usage: PmergeMe <positive_integer_sequence>" << endl;
        return 1;
    }
    vector<int> inputSequence;
    for (int i = 1; i < argc; i++) {
        inputSequence.push_back(atoi(argv[i]));
    }
    // Display unsorted sequence
    // cout << "Unsorted Sequence: ";
    // for (size_t i = 0; i < inputSequence.size(); i++) {
    //     cout << inputSequence[i] << " ";
    // }
    cout << endl;

    vector<int> sortedSequence(inputSequence);

    
    clock_t start = clock();                 // Start timing   
    insertionVec(sortedSequence);          // Sort the sequence using merge-insertion sort
    clock_t end = clock();                   // End timing

    double duration = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1e6; // Convert to microseconds

    // Display sorted sequence
    cout << "Sorted Sequence: ";
    for (size_t i = 0; i < sortedSequence.size(); i++) {
        cout << sortedSequence[i] << " ";
    }
    cout << endl;

    // Display time taken by the algorithm
    cout << "Time to process a range of " << inputSequence.size() << " elements: " << duration << " us" << endl;

    return 0;
}
