class Solution {
public:
    vector<int> sortByFreq(int arr[], int n) {
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        vector<pair<int, int>> freqVec;
        for (auto it : freq) {
            freqVec.push_back(make_pair(it.first, it.second));
        }
        sort(freqVec.begin(), freqVec.end(), cmp);
        vector<int> res;
        for (auto it : freqVec) {
            int x = it.first;
            int count = it.second;
            for (int i = 0; i < count; i++) {
                res.push_back(x);
            }
        }
        return res;
    }
private:
    static bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }