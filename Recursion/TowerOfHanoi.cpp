class Solution{
    public:
    long long toh(int n, int from, int to, int aux) {
        int steps=0;
        if (n == 0) {
            return 0;
        }
        steps += toh(n-1, from, aux, to);
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        steps++;
        steps += toh(n-1, aux, to, from);
        return steps;
    }

};