#include <bits/stdc++.h>

using namespace std;

void fast_io() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main()
{
    fast_io();
    int N = 0; cin >> N;
    vector<int> g[N + 1];

    for(int i = 1; i < N; i++){
        int v1 = 0, v2 = 0; cin >> v1 >> v2;
        g[v1].emplace_back(v2); g[v2].emplace_back(v1);
    }

    vector<int> result(N + 1, 0);
    queue<int> q;
    
    q.push(1); result[1] = 1;
    while(!q.empty()){
        int currentNode = q.front(); q.pop();
        for(int neighborNode : g[currentNode]) if(result[neighborNode] == 0) {result[neighborNode] = currentNode; q.push(neighborNode);}
    }

    for(int i = 2; i <= N; i++) cout << result[i] << '\n';

    return 0;
}