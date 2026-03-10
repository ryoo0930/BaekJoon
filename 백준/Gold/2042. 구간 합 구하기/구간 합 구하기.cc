#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int N, M, K;
int H;

vector<ll> tree;

void update(int index, ll value);
void query(int start, int end);

int main() {
    fastIO(); solve(); return 0;
}

void solve() {    
    cin >> N >> M >> K;
    H = ceil(log2(N));
    tree.assign(1 << (H + 1), 0);

    for(int i = 0; i < N; i++) { cin >> tree[(1 << H) + i]; }
    for(int i = ((1 << H) - 1); i > 0; i--) { tree[i] = tree[i * 2] + tree[i * 2 + 1]; }

    for(int i = 0; i < M + K; i++) {
        ll op, v1, v2; cin >> op >> v1 >> v2;

        if(op == 1) update(v1, v2);
        else if (op == 2) query(v1, v2);
    }

}

void update(int index, ll value) {
    index += (1 << H) - 1; tree[index] = value;
    while(index > 1) {
        index /= 2;
        tree[index] = tree[index * 2] + tree[index * 2 + 1];
    }
}

void query(int start, int end) {
    ll result = 0;
    start += (1 << H) - 1; end += (1 << H) - 1;

    while(start <= end) {
        if(start % 2 == 1) result += tree[start++];
        if(end % 2 == 0) result += tree[end--];

        start >>= 1;
        end >>= 1;
    }

    cout << result << '\n';
}