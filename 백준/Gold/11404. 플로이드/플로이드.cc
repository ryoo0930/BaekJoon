#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main(){
    fast_io();
    int N = 0, M = 0; cin >> N >> M;
    
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX));

    for(int i = 0; i < M; i++){
        int v1, v2, w; cin >> v1 >> v2 >> w;
        if(dist[v1][v2] > w) dist[v1][v2] = w;
    }

    for(int i = 1; i <= N; i++) { dist[i][i] = 0; }
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(dist[i][j] == INT_MAX) cout << '0' << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}