#include <bits/stdc++.h>
using namespace std;

void palindrome(string str){
    int low = 0, high = str.length()-1;
    bool flag = true;
    while  (low < high){

        if (str[low++] != str[high--]){
            cout << "The given String " << str << " is Not a Palindrome!" << endl;
            flag = false;
        }

        low ++;
        high --;

    }

    if (flag == true){
        cout << "The given String " << str << " is a Palindrome!" << endl;
    }
}

int main(){

    string str;
    cout << "Please Enter String to check it is Palindrome or Not!\n";
    cin >> str;
    palindrome(str);    

}