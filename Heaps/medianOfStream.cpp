#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> medianOfStream(vector<int>& arr, int size)
{
    vector<double> ans;
    vector<int> sortedArr;
    
    for (int i = 0; i < size; i++)
    {
        sortedArr.push_back(arr[i]);
        sort(sortedArr.begin(), sortedArr.end());
        
        int mid = i / 2;
        double median;
        if (i % 2 == 0)
        {
            median = sortedArr[mid];
        }
        else
        {
            median = (sortedArr[mid] + sortedArr[mid + 1]) / 2.0;
        }
        
        ans.push_back(median);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 4, 5, 12, 13, 11, 19};
    int size = arr.size();

    vector<double> ans = medianOfStream(arr, size);

    cout << "Input array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Running medians: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
