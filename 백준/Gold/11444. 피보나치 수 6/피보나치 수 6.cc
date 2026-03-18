#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
using ll = long long;

ll N;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

vector<vector<ll>> multiply_matrix(vector<vector<ll>>& matrixA, vector<vector<ll>> matrixB);
vector<vector<ll>> pow_matrix(vector<vector<ll>> base_matrix, ll n);

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    cin >> N;
    
    if(N == 0) { cout << 0 << '\n'; return; }
    if(N == 1) { cout << 1 << '\n'; return; }

    vector<vector<ll>> start_matrix = {{1, 1}, {1, 0}};
    vector<vector<ll>> result = pow_matrix(start_matrix, N);
    cout << result[0][1] << '\n';

}

vector<vector<ll>> multiply_matrix(vector<vector<ll>>& matrixA, vector<vector<ll>> matrixB) {
    vector<vector<ll>> result(2, vector<ll>(2, 0));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

vector<vector<ll>> pow_matrix(vector<vector<ll>> base_matrix, ll n) {
    vector<vector<ll>> result_matrix = {{1, 0}, {0, 1}};
    
    while(n > 0) {
        if(n % 2 == 1) result_matrix = multiply_matrix(result_matrix, base_matrix);
        base_matrix = multiply_matrix(base_matrix, base_matrix); n /= 2;
    }
    return result_matrix;
}