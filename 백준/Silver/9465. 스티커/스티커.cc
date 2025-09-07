#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void init_dp(vector<vector<int>>& arr, vector<vector<int>>& dp);

int main(){
    int testCase = 0; cin >> testCase;
    while(testCase--){
        int N = 0; cin >> N;
        vector<vector<int>> arr(2, vector<int>(N, 0)); // arr[i] = height
        for(int i = 0; i < 2; i++){ for(auto& var : arr[i]) cin >> var; }

        if(N == 1){ cout << max(arr[0][0], arr[1][0]) << '\n'; continue;}

        vector<vector<int>> dp(2, vector<int>(N, 0)); init_dp(arr, dp);
        for(int i = 2; i < N; i++){
            dp[0][i] = max({dp[1][i - 1], dp[0][i - 2], dp[1][i - 2]}) + arr[0][i];
            dp[1][i] = max({dp[0][i - 1], dp[0][i - 2], dp[1][i - 2]}) + arr[1][i];
        }
        cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';


    }
    

    return 0;
}

void init_dp(vector<vector<int>>& arr, vector<vector<int>>& dp){
    dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];
    dp[0][1] = dp[1][0] + arr[0][1]; dp[1][1] = dp[0][0] + arr[1][1];
    return;
}