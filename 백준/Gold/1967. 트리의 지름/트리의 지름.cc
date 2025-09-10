#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void DFS(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int currentNode, int value);

int maxSum = -1;
int maxNode = -1;

int main(){
    fast_io();
    int N; cin >> N;
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<bool> visited(N + 1, false);

    if(N == 1) {cout << 0 << '\n'; return 0;}
    for(int i = 0; i < N; i++){
        int v1, v2, w; cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2, w));
        graph[v2].push_back(make_pair(v1, w));
    }


    DFS(graph, visited, 1, 0);
    fill(visited.begin(), visited.end(), false);
    DFS(graph, visited, maxNode, 0);
    cout << maxSum << '\n';
    

    return 0;
}

void DFS(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int currentNode, int currentSum){
    visited[currentNode] = true;
    if(maxSum < currentSum) { maxSum = currentSum; maxNode = currentNode; }
    for(auto targetNode : graph[currentNode]){
        if(visited[targetNode.first]) continue;
        DFS(graph, visited, targetNode.first, currentSum + targetNode.second);
    }

}