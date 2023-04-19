#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generate(int N)
{
    queue<string> q;
    vector<string> result;

    // Enqueue the first binary number
    q.push("1");

    // Process all binary numbers from 1 to N
    while (N--)
    {
        // Dequeue a binary number from the front of the queue
        string s = q.front();
        q.pop();

        // Print the binary number
        result.push_back(s);

        // Enqueue two new binary numbers
        q.push(s + "0");
        q.push(s + "1");
    }

    return result;
}

int main()
{
    int N = 10; // generate binary numbers from 1 to 10
    vector<string> binaryNumbers = generate(N);

    // print the binary numbers
    cout << "Binary numbers from 1 to " << N << ":\n";
    for (int i = 0; i < binaryNumbers.size(); i++)
    {
        cout << binaryNumbers[i] << endl;
    }

    return 0;
}
