#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> mp;

    mp["gfg"] = 20;
    mp["ide"] = 25;
    mp["courses"] = 15;
    mp.insert({"Sahil", 23});

    for (auto it: mp){
        cout << it.first << " " << it.second << endl;
    }

    if (mp.find("ide") != mp.end()){
        cout <<  "Found" << endl;
    }

    else {
        cout << "Not Found" << endl;
    }

    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << it -> first << " " << it -> second <<endl;
    }
}