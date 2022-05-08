#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n2)
void bubbleSort(int *arr, int n)
{
    // To check if array is already sorted
    bool swapped = false;

    for (int i = 0; i < n - 1; i++)
    {
        // Traverse the array till the last-1 element as in bubble sort the last element is already getting sorted after every pass
        for (int j = 0; j < n - i - 1; j++)
        {
            // As we are comparing the element with it's next element so traverse till n-i-1
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
    }

    // If swapped boolean stays false that means array is already sorted
    if (!swapped)
        cout << "Array is already sorted\n";
}

// Time complexity: O(n2)
// Insertion sort is like a card game where every time we take the card and place it in it's appropriate positio
void insertionSort(int *arr, int n)
{
    int j, temp;
    // Starting array from 1 as we need to check previous elements
    // So in this case first element will be compared with it's previous element i.e., 0th position
    for (int i = 1; i < n; i++)
    {
        // Start j from 1 position back to traverse all the previous element
        // Place current element in temp
        j = i - 1;
        temp = arr[i];

        // Check all previous element and place current element at it's sorted position
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // As we are doing j-- in above array so array index might go one step back from sorted position so use j+1 to place it at correct index
        arr[j + 1] = temp;
    }
}

// Time complexity: O(n2)
// Finding the minimum element from array and placing it in it's correct position
// After every pass min element starting from (0-current_index) are sorted
void selectionSort(int *arr, int n)
{
    int i, j, index;
    for (i = 0; i < n - 1; i++)
    {
        index = i;
        // Find out the minimum element from array (it's index)
        for (j = i + 1; j < n; j++)
        {
            // If minimum element is found let index point to that value
            if (arr[j] < arr[index])
                index = j;
        }
        swap(arr[index], arr[i]);
    }
}

// If elements are in ascending or descending order quick sort will take O(n2) time
// Best case when pivot comes in middle of list O(nlogn)
// Partition function will place the pivot element at it's correct position and element lesser than pivot position will
// be lesser and greater than  pivot will be greater elemens
int partition(int low, int high, int *arr)
{
    // Initial element set as pivot
    int pivot = arr[low];

    // Set i and j to low and high
    int i = low;
    int j = high;

    // Start traversing i till the element is lesser than pivot and j till element is greater than pivot
    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        // At this time arr[i] is greater than pivot and arr[j] lesser than pivot
        // If i<j just swap them
        if (i < j)
            swap(arr[i], arr[j]);
    }

    // This is the case when i>j and j is the position where pivot element needs to be sorted
    swap(arr[j], arr[low]);

    return j;
}

// Worst Time complexity: O(n2), Best & Average Time Complexity: O(nlogn)
void quickSort(int *arr, int low, int high)
{
    // Sort the elements with help of pivot. Always place pivot at it's correct position.
    // Then again sort element lesser than pivot by setting it's first element as pivot
    // In second function call sort elements which are greater than pivot element in this case well next pivot element will be arr[pivot+1]
    if (low < high) // This condition means we have minimum two elements to sort
    {
        int pivot = partition(low, high, arr);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// To merge two sorted arrays
void merge(int *arr, int low, int mid, int high)
{
    // Low to Mid is one array and Mid+1 to high is second array
    // Place i'th pointer on first array and j'th pointer on second array
    // Use temporary third array to store merged two sorted arrays
    int temp[high + 1];
    int tempCount = low;
    int i = low;
    int j = mid + 1;

    // If element from i'th position is smaller place it in count array and increment i else place j'th index and increment j
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[tempCount++] = arr[i++];
        else
            temp[tempCount++] = arr[j++];
    }

    // Copying rest of the element from both the array if any
    while (i <= mid)
        temp[tempCount++] = arr[i++];

    while (j <= high)
        temp[tempCount++] = arr[j++];

    // Coping all the elements from temporary array to original array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i];
}

// Time complexity: O(nlogn)
//  Recursive Way: Top Down Approach
void mergeSort(int *arr, int low, int high)
{
    if (low < high) // This condition means we have minimum two elements to sort
    {
        // Divide the array into two halves until it reaches to a sinlge element and then start merging them
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

// Iterative Way: Bottom Up Approach
// Advantage: It doesn't uses extra space to store recursion calls
void mergeSortIterative(int *arr, int high)
{
    // First merge subarrays of size 1 to create sorted subarrays of size 2,
    // then merge subarrays of size 2 to create sorted subarrays of size 4, and so on.
    for (int m = 1; m <= high; m = 2 * m)
    {
        // for m = 1, i = 0, 2, 4, 6, 8…
        // for m = 2, i = 0, 4, 8…
        // for m = 4, i = 0, 8…
        for (int i = 0; i < high; i += 2 * m)
        {
            // Find ending point of left subarray. mid+1 is starting
            // point of right
            int newLow = i;
            int mid = min(i + m - 1, high);
            int newHigh = min(i + 2 * m - 1, high);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(arr, newLow, mid, newHigh);
        }
    }
}

void countSort(int *arr, int n)
{
    int count = 0;
    int maxElementFromArray = (*max_element(arr, arr + n)) + 1;
    // Finding out max element from  array and creating array of (max element+1) size

    // Initializing all the elements to 0
    int freqArr[maxElementFromArray] = {0};

    // Storing the frequence of each element in an array
    for (int i = 0; i < n; i++)
    {
        freqArr[arr[i]]++;
    }

    // Iterating over the frequence array and if any element is having size greater than 0
    //  then put that element in original array until that index element goes to 0
    for (int i = 0; i < maxElementFromArray; i++)
    {
        while (freqArr[i] > 0)
        {
            arr[count++] = i;
            freqArr[i]--;
        }
    }
}

/* Bucket Sort is similar to Count sort (But uses LinkedList as bucket chain)
Bucket Sort is a sorting algorithm that divides the unsorted array elements into several groups
called buckets. Each bucket is then sorted by using any of the suitable sorting algorithms or
recursively applying the same bucket algorithm.
Finally, the sorted buckets are combined to form a final sorted array.*/

/*Shell sort is a highly efficient sorting algorithm and is based on insertion sort algorithm.
Here, we find the gap by dividing the size/2 and comparing it with previous element to make it sorted.
*/
void shellSort(int *arr, int n)
{
    // start from the position n/2
    int gap = n / 2;
    while (gap > 0)
    {
        // start traversing from the gap till the last element
        for (int j = gap; j < n; j++)
        {
            // Store the element at gap in temp and check the last gap position which is the iterator (j-gap)
            // and if the previous element is found to be greater than gap just replace it and do it again until the previous element
            // is smaller or we are at the beginning of araay
            int temp = arr[j];
            int i = j - gap;
            while (i >= 0 && arr[i] > temp)
            {
                arr[i + gap] = arr[i];
                i = i - gap;
            }
            arr[i + gap] = temp;
        }
        // Once one gap pass is completed all the gap position are sorted
        // Then again divide gap by 2
        gap = gap / 2;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // bubbleSort(arr,n);

    // insertionSort(arr,n);

    // selectionSort(arr,n);

    // quickSort(arr,0,n-1);

    // mergeSort(arr,0,n-1);

    // mergeSortIterative(arr, n - 1);

    // countSort(arr,n);

    shellSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}