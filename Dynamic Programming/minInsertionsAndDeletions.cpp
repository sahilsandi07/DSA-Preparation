#include <bits/stdc++.h> 
using namespace std;
int lcs (string &text1, string &text2) {
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

    return prev[m];
}

int canYouMake(string &s1, string &s2){
    return s1.size() + s2.size() - 2 * lcs (s1, s2);
}

int main() {
    string s1 = "abcd";
    string s2 = "anc";

    cout << "Min Operations required to make string s equal are: " << canYouMake (s1, s2) << endl;
    return 0;
}