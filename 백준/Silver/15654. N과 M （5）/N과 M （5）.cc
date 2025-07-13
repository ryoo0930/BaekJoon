#include <bits/stdc++.h>

using namespace std;

void fast_io() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

void DFS(vector<int>& v, vector<int>& r, vector<bool>& visited, int depth, int N, int M){
    if(depth == M){
        for(auto i : r) cout << i << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            visited[i] = true;
            r[depth] = v[i];
            DFS(v, r, visited, depth + 1, N, M);
            visited[i] = false;
        }
    }
}

int main()
{
    fast_io();
    int N = 0, M = 0; cin >> N >> M;
    vector<int> v(N);
    for(auto& i : v) cin >> i;
    sort(v.begin(), v.end());
    
    vector<int> r(M);
    vector<bool> visited(N, false);
    DFS(v, r, visited, 0, N, M);

    return 0;
}