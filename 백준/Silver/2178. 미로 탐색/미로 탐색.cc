#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();
void BFS(const vector<vector<char>>& graph, vector<vector<int>>& distance, int x, int y);

int dx[4] {-1, 1, 0, 0};
int dy[4] {0, 0, -1, 1};

int main() {
    fastIO(); solve(); return 0;
}

int result = 1;
int n = 0, m = 0;
void solve() {
    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<int>> distance(n, vector<int>(m, -1));

    for(auto& i : graph) { for(auto& j : i) cin >> j; }
    
    BFS(graph, distance, 0, 0);

}

void BFS(const vector<vector<char>>& graph, vector<vector<int>>& distance, int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0)); distance[0][0] = 1;

    while(!q.empty()) {
        pair<int, int> currentPosition = q.front(); q.pop();
        if(currentPosition.first == n - 1 && currentPosition.second == m - 1) {cout << distance[n - 1][m - 1]; break;}
        for(int i = 0; i < 4; i++) {
            int targetX = currentPosition.first + dx[i], targetY = currentPosition.second + dy[i];
            if(targetX >= 0 && targetX < n && targetY >= 0 && targetY < m && graph[targetX][targetY] == '1' && distance[targetX][targetY] == -1) {
                q.push(make_pair(targetX, targetY));
                distance[targetX][targetY] = distance[currentPosition.first][currentPosition.second] + 1;

            }
        }
    }   
}
 