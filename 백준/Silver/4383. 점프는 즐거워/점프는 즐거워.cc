#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    int n = 0;
    while(cin >> n) {
        
        bool isJolly = true;
        vector<int> v(n);
        vector<int> abs_value;
        for(auto& i : v) { cin >> i; }
        
        for(int i = 0; i < n - 1; i++) {
            int temp = abs(v[i] - v[i + 1]);
            abs_value.push_back(temp);
        }
        
        sort(abs_value.begin(), abs_value.end());
        int len = abs_value.size();
        for(int i = 0; i < len; i++) {
            if (!(abs_value[i] == i + 1)) isJolly = false;
        }
        

        if(isJolly) cout << "Jolly" << '\n';
        else cout << "Not jolly" << '\n';
    }
}

