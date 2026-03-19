#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int C, N;

int main() {
    fastIO(); solve(); return 0;
}

void solve() {    
    cin >> C >> N;
    vector<pair<int, int>> v(N);
    vector<int> dp(C + 100001, 0);

    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

    for(auto& i : v) {
        int cost = i.first, customer = i.second;
            
        for(int k = cost; k < C + 100001; k++) {
            dp[k] = max(dp[k], dp[k - cost] + customer);
        }
    }

    int result = lower_bound(dp.begin(), dp.end(), C) - dp.begin();

    cout << result;
}
