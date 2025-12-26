#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    int testCase = 0; cin >> testCase;
    while(testCase--) {
        int size = 0, target = 0; cin >> size >> target;
        queue<pair<int, int>> q;
        priority_queue<int, vector<int>, less<int>> pq;

        for(int i = 0; i < size; i++) {
            int priority = 0; cin >> priority;
            q.push(make_pair(i, priority)); // first = index, second = priority
            pq.push(priority);
        }


        int result = 1;
        while(!q.empty()) {
            int top_priority = pq.top(); pq.pop();
            pair<int, int> top_queue = make_pair(-1, -1);

            while(top_queue.second != top_priority) {
                top_queue = q.front(); q.pop();
                if(top_queue.second != top_priority) q.push(top_queue);
            }

            if(top_queue.first == target) break;
            else result++;
        }

        cout << result << '\n';
    }
}

