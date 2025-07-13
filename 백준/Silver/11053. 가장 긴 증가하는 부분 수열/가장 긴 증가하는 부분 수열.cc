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
    vector<int> v(N);
    for(auto& i : v) cin >> i;

    vector<int> dp(N, 1);
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}