#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main()
{
    fast_io();
    int T, N; cin >> T >> N;
    vector<int> F(N); for(auto& i : F) cin >> i;

    int sum = 0; for(auto i : F) sum += i;
    if(sum >= T) cout << "Padaeng_i Happy";
    else cout << "Padaeng_i Cry";
    
    return 0;
}