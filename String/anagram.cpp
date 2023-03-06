#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s1, string s2){
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> mp;

    for(int i=0; i<s1.length(); i++){
        mp[s1[i]]++;
    }
    
    for(int i=0; i<s2.length(); i++){
        mp[s2[i]]--;
    }

    for (auto it : mp){
        if (it.second != 0){
            return false;
        }
    }

    return true;    
}

int main(){

    string s1, s2;
    cout << "Enter two strings S1 and S2:\n";
    cin >> s1 >> s2;

    if (isAnagram(s1, s2)){
        cout << s2 << " is an Anagram of " << s1 << endl;
    }
    else {
        cout << s2 << " is not an Anagram of " << s1 << endl;
    }

}