#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    string input; cin >> input;
    
    int result = 0, len = 1;
    int input_len = input.length();
    while(len <= (input_len / 2)) {
        for(int i = 0; i <= input_len - (2 * len); i++) {
            int leftSize = 0, rightSize = 0;

            for(int j = i; j < i + len; j++) {
                leftSize += input[j] - '0';
            }
            for(int j = i + len; j < i + (2 * len); j++) {
                rightSize += input[j] - '0';
            }

            if(leftSize == rightSize) { result = len * 2; break; }
        }
        len++;
    }

    cout << result;

}

