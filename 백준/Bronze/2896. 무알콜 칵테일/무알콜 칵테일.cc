#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
using ll = long long;


void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    double A, B, C; cin >> A >> B >> C;
    double I, J, K; cin >> I >> J >> K;

    double ratio = min({A / I, B / J, C / K});

    cout << fixed << setprecision(6);
    cout << A - (I * ratio) << ' ' << B - (J * ratio) << ' ' << C - (K * ratio);
}