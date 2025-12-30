#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    int n = 0, m = 0; cin >> n >> m;
    string input; cin >> input;

    int count = 0, result = 0;
    for(int i = 1; i < m - 1;) {
        if(input[i] == 'O' && input[i + 1] == 'I') {
            count++;
            if(count == n) { if(input[i - ((2 * count) - 1)] == 'I') result++; count--; }
            i += 2;
        }
        else { count = 0; i++; }
    }

    cout << result;
}
