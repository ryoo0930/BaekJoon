#include <bits/stdc++.h>

using namespace std;
int n = 0, m = 0;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

bool check(int x, int y);

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1 ,-1};

int main() {
    fastIO(); solve(); return 0;
}


void solve() {
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));

    for(auto& i : graph) { for(auto& j : i) cin >> j; }

    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, -1))); // x, y 좌표 + [벽을 부수지 않은 세계 = 0 / 벽을 부슨 세계 = 1]
    visited[0][0][0] = 1; visited[0][0][1] = 1; // 초기 상태

    queue<pair<pair<int, int>, bool>> q; // x, y 좌표 + 벽 상태
    q.push(make_pair(make_pair(0, 0), 0));

    while(!q.empty()) {
        pair<pair<int, int>, int> current = q.front(); q.pop();
        int cx = current.first.first; int cy = current.first.second; int cw = current.second;

        if(cx == n - 1 && cy == m - 1) { cout << visited[cx][cy][cw] << '\n'; return; }

        for(int i = 0; i < 4; i++) {
            int tx = cx + dx[i], ty = cy + dy[i];

            if(!check(tx, ty)) continue;
            int tw = graph[tx][ty] - '0';

            if((cw == 1 && tw == 1) || (visited[tx][ty][cw || tw] != -1)) continue;
            visited[tx][ty][cw || tw] = visited[cx][cy][cw] + 1;
            q.push(make_pair(make_pair(tx, ty), cw || tw));
        }
        
    }

    cout << "-1";

}

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}