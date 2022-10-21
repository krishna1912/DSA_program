// THIS IS THE IMPLEMENTATION OF QUICKSORT ALGORITM IN C++

#include <iostream>
#include <vector>

using namespace std;

// basic swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// This function takes the last ('end') array element as pivot and rearranges the array such that
// all elements to the left of the pivot are smaller or equal to its magnitude and all elements to
// the right of it are greater than it, in magnitude.
// This function returns the final index value of the pivot after the rearrangement, logically partitioning it.
// 'start' and 'end' are the exact array indices within which the partitioning is to be done
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int pos = start;
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[pos], &arr[j]);
            pos++;
        }
    }
    swap(&arr[pos], &arr[end]);
    return pos;
}

// This is the main quicksort function that calls itself on the left and right sides 
// of the partition (split) position.
// 'start' and 'end' are the exact array indices within which the sorting is to be done
void quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int split = partition(arr, start, end);
        quickSort(arr, start, split - 1);
        quickSort(arr, split + 1, end);
    }
}

// main driver code
int main()
{
    vector<int> arr;
    int n;
    
    cout << "Enter the number of values to be sorted: ";
    cin >> n;

    cout << "Enter the values one by one with a space in between: ";
    int temp;
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    quickSort(arr, 0, (n - 1));

    cout << "The sorted array is: ";
    for (int i=0; i<n; i++) {
        cout << arr.at(i) << ", ";
    }

    return 0;
}