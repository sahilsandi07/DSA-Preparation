// #include<bits/stdc++.h>
// using namespace std;

// void longestSubStr(string &str) {
//     int n = str.size();
//     int res = 0;
//     vector <int> prev(256, -1);
//     int i = 0;
//     for (int j=0; j<n; j++){
//         i = max(i, prev[str[j]] + 1);
//         int maxEnd = j - i + 1;
//         res = max (res, maxEnd);
//         prev[str[i]] = j;
//     }
//     cout << "The length of longest substring with distinct elements is: " << res << endl;
// }

// int main() {
//     string str;
//     cout << "Enter the String: \n" ;
//     cin >> str;
//     longestSubStr(str);
// }

#include <bits/stdc++.h>
using namespace std;

void longestSubStr(string &str)
{
    int n = str.size();
    int res = 0, start = 0;
    vector<int> prev(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        int maxEnd = j - i + 1;
        if (res < maxEnd)
        {
            res = maxEnd;
            start = i;
        }
        prev[str[j]] = j;
    }
    cout << "The longest substring with distinct elements is: " << str.substr(start, res) << endl;
}

int main()
{
    string str;
    cout << "Enter the String: \n";
    cin >> str;
    longestSubStr(str);
}
