#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();
void DFS(vector<vector<int>>& g, vector<vector<bool>>& visited, pair<int, int> pos, int current, int depth);

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int result = 0;

int main() {
    fastIO(); 
    solve(); 
    return 0;
}

void solve() {    
    cin >> N >> M;
    vector<vector<int>> g(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) cin >> g[i][j];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(g, visited, make_pair(i, j), g[i][j], 1);
            visited[i][j] = false;
        }
    }

    cout << result;
}

void DFS(vector<vector<int>>& g, vector<vector<bool>>& visited, pair<int, int> pos, int current, int depth) {
    if(depth == 4) { 
        result = max(result, current); 
        return; 
    }

    int currentX = pos.first, currentY = pos.second;
    for(int i = 0; i < 4; i++) {
        int targetX = currentX + dx[i], targetY = currentY + dy[i];
        
        if(targetX >= 0 && targetX < N && targetY >= 0 && targetY < M && !visited[targetX][targetY]) {
            
            if(depth == 2) {
                visited[targetX][targetY] = true;
                DFS(g, visited, pos, current + g[targetX][targetY], depth + 1);
                visited[targetX][targetY] = false;
            }

            visited[targetX][targetY] = true;
            DFS(g, visited, make_pair(targetX, targetY), current + g[targetX][targetY], depth + 1);
            visited[targetX][targetY] = false;
        }
    }
}