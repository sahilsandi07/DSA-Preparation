#include<bits/stdc++.h>
using namespace std;
const int CHAR = 256;

int leftMost(string str){
    bool visited[CHAR];
    fill(visited, visited+CHAR, false);

    int res  = -1;
    for (int i=str.length()-1; i>=0; i--){
        if(visited[str[i]]){
            res = i;
        }
        else {
            visited[str[i]] = true;
        }
    }
    return res;
}

int main() {
    string str;
    cout << "Enter the STring:\n";
    cin >> str;
    cout << "The Leftmost Repeating character is at Index: " << leftMost(str) << endl;
}