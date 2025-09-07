#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main(){
    int N = 0; cin >> N;
    vector<vector<int>> arr(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = arr[0][0];
    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = dp[i - 1][j] + arr[i][j];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
        }
    }
    
    cout << *max_element(dp[N - 1].begin(), dp[N - 1].end()) << '\n';


    return 0;
}