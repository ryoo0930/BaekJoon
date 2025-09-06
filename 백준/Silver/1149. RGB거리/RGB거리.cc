#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main()
{
    
    int N = 0; cin >> N;
    vector<vector<int>> arr(N, vector<int>(3));
    for(auto& i : arr){ for(auto& var : i) cin >> var; }// 0 = red, 1 = green, 2 = blue

    vector<vector<int>> dp(N, vector<int>(3));
    for(int i = 0; i < 3; i++){ dp[0][i] = arr[0][i]; } // dp[i][0] = red First | dp[i][1] = green First | dp[i][2] = blue First

    for(int i = 1; i < N; i++){
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    }
    
    cout << *min_element(dp[N-1].begin(), dp[N-1].end()) << '\n';

    return 0;
}