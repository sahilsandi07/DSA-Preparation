#include<bits/stdc++.h>
using namespace std;

void naiveSearch (string &txt, string &pat){
    int m = pat.length(), n = txt.length();
    for (int i=0; i<=n-m; i++){
        int j;
        for (j=0; j<m; j++){
            if (pat[j] != txt[i+j]){
                break;
            }
        }

        if (j == m){
            cout << i << " ";
        }
    }
}

int main(){
    string txt = "AAAAA";
    string pat = "AAA";

    naiveSearch(txt, pat);
}