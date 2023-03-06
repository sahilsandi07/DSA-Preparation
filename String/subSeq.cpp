#include<bits/stdc++.h>
using namespace std;

bool isSub(string s1, string s2){
    if (s2.length() > s1.length())  return false;
    int j = 0;
    for (int i=0; i<s1.length() && j<s2.length(); i++){
        if (s1[i] == s2[j++]);
    }
    return (j==s2.length());
}

int main(){

    string s1, s2;
    cout << "Enter two strings S1 and S2:\n";
    cin >> s1 >> s2;

    if (isSub(s1, s2)){
        cout << s2 << " is a Sub Sequence of " << s1 << endl;
    }
    else {
        cout << s2 << " is not a Sub Sequence of " << s1 << endl;
    }

}