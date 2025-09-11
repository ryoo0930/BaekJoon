#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main(){
    fast_io();
    int testCase = 0; cin >> testCase;
    while(testCase--){
        int N, M, W; cin >> N >> M >> W;
        vector<vector<int>> graph(N + 1, vector<int>(N + 1, INT_MAX));
        for(int i = 0; i < M; i++){
            int v1, v2, w; cin >> v1 >> v2 >> w;
            if(graph[v1][v2] > w) { graph[v1][v2] = w; graph[v2][v1] = w; }
        }
        for(int i = 0; i < W; i++){
            int v1, v2, w; cin >> v1 >> v2 >> w;
            if(graph[v1][v2] > -w) { graph[v1][v2] = -w; }
        }
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    if(graph[i][j] > graph[i][k] + graph[k][j] && graph[i][k] != INT_MAX && graph[k][j] != INT_MAX){ graph[i][j] = graph[i][k] + graph[k][j]; }
                }
            }
        }

        bool flag = false;
        for(int startV = 1; startV <= N; startV++){
            for(int targetV = 1; targetV <= N; targetV++){
                if(graph[startV][targetV] != INT_MAX && graph[targetV][startV] != INT_MAX && graph[startV][targetV] + graph[targetV][startV] < 0) { flag = true; break; }
            }
            if(flag) break;
        }

        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
    return 0;
}