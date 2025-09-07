#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main(){
    fast_io();
    
    int N, M; cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(N + 1, 0));
    for(int i = 0; i < N; i++){ 
        for(int j = 1; j <= N; j++) { cin >> arr[i][j]; } 
    }

    vector<vector<int>> dp(N, vector<int>(N + 1, 0));
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= N; j++){ dp[i][j] = dp[i][j - 1] + arr[i][j]; }
    }


    for(int i = 0; i < M; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        for(int k = x1 - 1; k < x2; k++){ sum += dp[k][y2] - dp[k][y1 - 1]; }
        cout << sum << '\n';
    }

    return 0;
}
