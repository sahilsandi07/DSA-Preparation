#include<bits/stdc++.h>
using namespace std;

const int ch = 256;
int leftMostNonRep(string str){
    int fI[ch];
    fill(fI, fI + ch, -1);

    for(int i=0; i<str.length(); i++){
        if (fI[str[i]] == -1){
            fI[str[i]] = i;
        }
        else{
            fI[str[i]] = -2;
        }
    }

    int res = INT_MAX;
    for (int i=0; i<ch; i++){
        if (fI[i] >= 0){
            res = min(res, fI[i]);
        }
    }
    return (res == INT_MAX) ? -1 : res;
}

int main() {
    string str;
    cout << "Enter the String:\n";
    cin >> str;
    cout << "The leftmost non Repeating Character is: " << leftMostNonRep(str) << endl;
}