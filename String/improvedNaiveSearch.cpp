#include<bits/stdc++.h>
using namespace std;

void naiveSearch (string &txt, string &pat){
    int m = pat.length(), n = txt.length();
    for (int i=0; i<=n-m; ){
        int j;
        for (j=0; j<m; j++){
            if (pat[j] != txt[i+j]){
                break;
            }
        }

        if (j == m){
            cout << i << " ";
        }

        if (j == 0){
            i++;
        }
        else {
            i += j;
        }
    }
}

int main(){
    string txt = "ABCABCDABCD";
    string pat = "ABCD"; // all  chars in pattern are distinct

    naiveSearch(txt, pat);
}