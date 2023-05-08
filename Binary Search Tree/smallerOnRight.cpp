#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

int maxNumberOfSmallerElements(const vector<int> &v, int N)
{
    if (N == 0)
        return 0;
    set<int> s;
    int res = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        s.insert(v[i]);
        auto it = s.find(v[i]);
        res = max(res, static_cast<int>(distance(s.begin(), it)));
    }
    return res;
}

int main()
{
    // code
    int T = 0;
    cin >> T;
    while (T--)
    {
        int n = 0;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; ++i)
        {
            int el = 0;
            cin >> el;
            v.push_back(el);
        }
        cout << maxNumberOfSmallerElements(v, v.size()) << endl;
    }
    return 0;
}
