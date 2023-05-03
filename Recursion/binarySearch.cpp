#include<bits/stdc++.h>
using namespace std;

void print (int arr[], int start, int end)
{
    for (int i=start; i<=end; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;
}

int binarySearch (int *arr, int start, int end, int key)
{
    cout << endl;
    print (arr, start, end);
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    else
    {
        if (arr[mid] > key)
        {
            return binarySearch(arr, start, mid - 1, key);
        }
        else
        {
            return binarySearch(arr, mid + 1, end, key);
        }
    }
}

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    int key = 11;
    if (binarySearch(arr, 0, n-1, key) == -1)
    {
        cout << "Element Not Present." << endl;
    }
    else
        cout << key << " is present at index " << binarySearch(arr, 0, n-1, key) << endl;
    return 0;
}