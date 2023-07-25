#include<bits/stdc++.h>
using namespace std;

void printLCS (string &text1, string &text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int> curr (m+1, 0);
    vector<int> prev (m+1, 0);

    for (int i=1 ;i<=n; i++) {
        for (int j=1; j<=m; j++) {
            // if the character matches
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + prev[j-1];
            }
            
            else curr[j] = max (prev[j], curr[j-1]);
        }

        prev = curr;
    }

    int len = prev[m];
    string ans = "";
    for (int i=0; i<len; i++) {
        ans += '$';
    }

    int index = len - 1;
    int i = n, j = m;

    while (i>0 && j > 0) {
        if (text1[i-1] == text2[j-1]) {
            ans[index] = text1[i-1];
            index--;
            i--;
            j--;
        }

        else if (prev[j] > curr[j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    cout << ans << endl;
}

int main () {
    string s1 = "abcde";
    string s2 = "bdgek";
    printLCS (s1, s2);
    return 0;
}