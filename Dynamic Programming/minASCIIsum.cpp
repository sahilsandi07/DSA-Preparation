struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
private:
    // Hash Map to store the result of each sub-problem.
    unordered_map<pair<int, int>, int, hash_pair> savedResult;
public:
    int minimumDeleteSum(string s1, string s2) {
        // 1 -> Recursion
        // return solveRec(s1, s2, 0, 0);

        // 2 -> Memoization
        return computeCost(s1, s2, s1.length() - 1, s2.length() - 1);        
    }

private:
    int solveRec(const string& s1, const string& s2, int i, int j) {
        if (i == s1.length()) {
            int sum = 0;
            for (; j < s2.length(); j++) {
                sum += s2[j];
            }
            return sum;
        }

        if (j == s2.length()) {
            int sum = 0;
            for (; i < s1.length(); i++) {
                sum += s1[i];
            }
            return sum;
        }

        if (s1[i] == s2[j]) {
            return solveRec(s1, s2, i + 1, j + 1);
        }

        int deleteS1 = s1[i] + solveRec(s1, s2, i + 1, j);
        int deleteS2 = s2[j] + solveRec(s1, s2, i, j + 1);

        return min(deleteS1, deleteS2);
    }
    private:
    int computeCost(const string& s1, const string& s2, int i, int j) {
        // If both strings are empty, then no deletion is required
        if (i < 0 && j < 0) {
            return 0;
        }

        // If already computed, then return the result from the hash map
        pair<int, int> key(i, j);
        if (savedResult.count(key)) {
            return savedResult[key];
        }

        // If any one string is empty, delete all characters of the other string
        if (i < 0) {
            savedResult[key] = s2[j] + computeCost(s1, s2, i, j - 1);
            return savedResult[key];
        }
        if (j < 0) {
            savedResult[key] = s1[i] + computeCost(s1, s2, i - 1, j);
            return savedResult[key];
        }

        // Call sub-problem depending on s1[i] and s2[j]
        // Save the computed result.
        if (s1[i] == s2[j]) {
            savedResult[key] = computeCost(s1, s2, i - 1, j - 1);
        } else {
            savedResult[key] = min(
                s1[i] + computeCost(s1, s2, i - 1, j),
                s2[j] + computeCost(s1, s2, i, j - 1)
            );
        }
        return savedResult[key];
    }
};