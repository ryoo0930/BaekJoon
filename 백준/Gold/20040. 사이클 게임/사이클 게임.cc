#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();


int N, M;
vector<int> parent;

int find(int x);
bool unite(int x, int y);

int main() {
    fastIO(); solve(); return 0;
}

void solve() {    
    cin >> N >> M;
    parent.resize(N);
    for(int i = 0; i < N; i++) parent[i] = i;

    int result = 0;

    for(int i = 1; i <= M; i++) {
        int v1, v2; cin >> v1 >> v2;
    
        if(result == 0 && !unite(v1, v2)) result = i;
    }

    cout << result;
}

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return false;
    
    if(x < y) parent[y] = x;
    else parent[x] = y;
    return true;
}