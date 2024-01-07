#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void bubbleSort(int size, int arr[])
{
    int comparisons = 0;
    for (int j = 0; j < size - 1; j++)
    {
        comparisons++;

        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                display(size, arr);
            }
        }
    }
    cout << "Final Array" << endl;
    display(size, arr);
    cout << endl
         << "Bubble Sort Comparisons: " << comparisons << endl;
}

void selectionSort(int size, int arr[])
{
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        comparisons++;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            display(size, arr);
            swap(arr[i], arr[min]);
        }
    }
    cout << "Final Array" << endl;
    display(size, arr);
    cout << "Selection Sort Comparisons: " << comparisons << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid; 

    int leftArr[leftSize];
    int rightArr[rightSize]; 

    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[left + i];
    } 
    for (int j = 0; j < rightSize; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;


    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    
    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    merge(arr, l, mid, r);
}

int binarySearchRecursive(int arr[], int left, int right, int key, int &comparisons)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            comparisons++;
            return binarySearchRecursive(arr, left, mid - 1, key, comparisons);
        }
        else
        {
            comparisons++;
            return binarySearchRecursive(arr, mid + 1, right, key, comparisons);
        }
    }

    return -1;
}

int binarySearchIterative(int arr[], int size, int key, int &comparisons)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            comparisons++;
            right = mid - 1;
        }
        else
        {
            comparisons++;
            left = mid + 1;
        }
    }

    return -1;
}
int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }


    cout << "\nMenu:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Binary Search (Recursive)\n";
    cout << "5. Binary Search (Iterative)\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        bubbleSort(size, arr);
        break;
    case 2:
        selectionSort(size, arr);
        break;
    case 3:
        mergeSort(arr, 0, size);
        display(size, arr);
        break;
    case 4:
    {
        int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        int result = binarySearchRecursive(arr, 0, size, key, comparisons);
        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found\n";
        }
        cout << "Comparisons: " << comparisons << endl;
        break;
    }
    case 5:
    {
        int key;
        cout << "Enter the value to find: ";
        cin >> key;
        int comparisons = 0;
        int result = binarySearchIterative(arr, size, key, comparisons);
        if (result != -1)
        {
            cout << "Element found at index " << result << endl;
        }
        else
        {
            cout << "Element not found\n";
        }
        cout << "Comparisons: " << comparisons << endl;
        break;
    }
    default:
        cout << "Invalid choice\n";
    }

    return 0;
}