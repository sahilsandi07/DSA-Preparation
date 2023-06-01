#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // step 1 : create a queue and push the start and a step of 1
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        
        // step 2 : create an unordered set of wordList
        unordered_set<string> st (wordList.begin(), wordList.end());
        
        // step 3 : iterate till queue becomes empty or we reach the target word
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if (word == targetWord) return steps;
            
            for (int i=0; i<word.size(); i++) {
                char original_word = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push ({word, steps+1});
                    }
                }
                word[i] = original_word;
            }
        }
        
        return 0;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}