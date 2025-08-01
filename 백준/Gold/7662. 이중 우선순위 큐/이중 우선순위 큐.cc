#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <functional>
using namespace std;

void fastIO() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void sync(priority_queue<int, vector<int>, less<int>>& pq, map<int, int>& m) {
    while (!pq.empty() && m[pq.top()] == 0) {
        pq.pop();
    }
}

void sync(priority_queue<int, vector<int>, greater<int>>& pq, map<int, int>& m) {
    while (!pq.empty() && m[pq.top()] == 0) {
        pq.pop();
    }
}

int main() {
    fastIO();

    int testCase = 0; cin >> testCase;
    while (testCase--) {
        priority_queue<int, vector<int>, less<int>> MaxQ;
        priority_queue<int, vector<int>, greater<int>> MinQ;
        map<int, int> counts;

        int operSize = 0; cin >> operSize;
        while (operSize--) {
            char oper; cin >> oper;
            if (oper == 'I') {
                int temp = 0; cin >> temp;
                MaxQ.push(temp); MinQ.push(temp);
                counts[temp]++;
            }

            if (oper == 'D') {
                int temp = 0; cin >> temp;

                if (temp == 1) {
                    sync(MaxQ, counts);
                    if (!MaxQ.empty()) {
                        counts[MaxQ.top()]--;
                        MaxQ.pop();
                    }
                }
                else if (temp == -1) {
                    sync(MinQ, counts);
                    if (!MinQ.empty()) {
                        counts[MinQ.top()]--;
                        MinQ.pop();
                    }
                }
            }
        }

        sync(MaxQ, counts); sync(MinQ, counts);

        if (MaxQ.empty() || MinQ.empty()) cout << "EMPTY" << '\n';
        else cout << MaxQ.top() << ' ' << MinQ.top() << '\n';
    }

    return 0;
}
