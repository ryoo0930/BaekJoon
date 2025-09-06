#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main()
{
    string str1, str2; cin >> str1 >> str2;
    int len1 = str1.length(), len2 = str2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(str1[i] == str2[j]){ dp[i + 1][j + 1] = dp[i][j] + 1; }
            else{dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]); }
        }
    }

    cout << dp[len1][len2] << '\n';
    return 0;
}