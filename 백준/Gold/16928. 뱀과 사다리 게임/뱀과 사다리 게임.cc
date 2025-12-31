#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    int ladderSize = 0, snakeSize = 0; cin >> ladderSize >> snakeSize;
    vector<int> warp(101, -1);
    for(int i = 0; i < ladderSize + snakeSize; i++) { int v1, v2; cin >> v1 >> v2; warp[v1] = v2; }

    vector<int> graph(101, INT_MAX); graph[1] = 0;
    queue<int> q; q.push(1);

    while(!q.empty()) {
        int current = q.front(); q.pop();
        if(current == 100) break;

        if(warp[current] != -1) {
            q.push(warp[current]);
            graph[warp[current]] = min(graph[warp[current]], graph[current]);
            continue;
        }

        for(int i = 1; i <= 6; i++) {
            int target = current + i; if(target > 100) break;
            if(target == INT_MAX || graph[target] > graph[current] + 1) { q.push(target); graph[target] = graph[current] + 1; }
        }
    }

    cout << graph[100] << '\n';
}
