class Solution {
  public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_set<int> set_a(a, a + n);  // Convert array a to a set
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (set_a.erase(b[i])) {  // If element in b is in set_a, erase it and increment count
                count++;
            }
        }
        return count;
    }
};