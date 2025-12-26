#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

void solve() {
    int size = 0; cin >> size;
    
    vector<int> v(size);
    for(auto& i : v) cin >> i;

    int left = 0, right = 0, result = 0;
    vector<int> count(10, 0); int typeCheck = 0;
    while(right < size) {
        if(count[v[right]] == 0) typeCheck++;
        count[v[right]]++;

        while(typeCheck > 2)  {
            count[v[left]]--;
            if(count[v[left]] == 0) typeCheck--;
            left++;
        }

        result = max(result, right - left + 1);
        right++;
    }
    cout << result;

}

