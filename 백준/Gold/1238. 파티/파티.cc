#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main(){
    fast_io();
    int N = 0, M = 0, X = 0; cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());
    for(int i = 0; i < M; i++){
        int v1, v2, w; cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2, w));
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair<dist, vertex>
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX));
    for(int startVertex = 1; startVertex <= N; startVertex++){
        pq.push(make_pair(0, startVertex));
        while(!pq.empty()){
            pair<int, int> current = pq.top(); pq.pop();
            if(dist[startVertex][current.second] < current.first) continue;

            for(auto neighbor : graph[current.second]) {
                int neighborVertex = neighbor.first;
                int weight = neighbor.second;

                int cost = current.first + weight;
                if(cost < dist[startVertex][neighborVertex]) { dist[startVertex][neighborVertex] = cost; pq.push(make_pair(cost, neighborVertex)); }
            }
        }
    }
    
    vector<int> result(N + 1, 0);
    for(int i = 1; i <= N; i++){ 
        if(i == X) continue;
        result[i] = dist[i][X] + dist[X][i];
     }

    cout << *max_element(result.begin(), result.end()) << '\n';



    
    return 0;
}