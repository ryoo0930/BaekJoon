#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int V, E;
vector<vector<pair<int, int>>> graph;


int main() {
    fastIO(); solve(); return 0;
}

void solve() {    
    cin >> V >> E;
    graph.assign(V + 1, vector<pair<int, int>>());

    pair<int, pair<int, int>> min_information = make_pair(INT_MAX, make_pair(0, 0));

    for(int i = 0; i < E; i++) {
        int v1, v2, w; cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(w, v2));
        graph[v2].push_back(make_pair(w, v1));

        if(w < min_information.first) { min_information.first = w; min_information.second = make_pair(v1, v2); }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V + 1, false);

    int result = 0;
    int currentEdgesCount = 0;
    pq.push(make_pair(0, 1));

    while(!pq.empty()) {
        int current_w = pq.top().first; int current_v = pq.top().second; pq.pop();
        if(visited[current_v]) continue;

        visited[current_v] = true; result += current_w; currentEdgesCount++;

        for(auto& i : graph[current_v]) { if(!visited[i.second]) { pq.push(i); } }
    }


    cout << result << '\n';

}