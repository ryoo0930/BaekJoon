#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
int compare(){

}

int main(){
    fast_io();
    int V = 0, E = 0; cin >> V >> E;
    int startV = 0; cin >> startV;
    
    vector<vector<pair<int, int>>> graph(V + 1, vector<pair<int, int>>());
    vector<int> dist(V + 1, INT_MAX);

    for(int i = 0; i < E; i++){
        int v1, v2, w; cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2, w));
    }


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // pair<cost, node>
    pq.push(make_pair(0, startV)); dist[startV] = 0;
    while(!pq.empty()){
        pair<int, int> current = pq.top(); pq.pop();
        if(dist[current.second] < current.first) continue;
        
        for(auto neighbor : graph[current.second]){
            int neighborNode = neighbor.first;
            int weight = neighbor.second;

            int cost = current.first + weight;
            if(cost < dist[neighborNode]){ dist[neighborNode] = cost; pq.push(make_pair(cost, neighborNode)); }
        }
    }

    for(int i = 1; i <= V; i++){
        if(dist[i] == INT_MAX) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}