#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main(){
    ll A, B, C; cin >> A >> B >> C;
    vector<ll> pow_arr; pow_arr.push_back(A);

    for(ll i = 1; i <= B; i += i){
        pow_arr.push_back((pow_arr[pow_arr.size() - 1] * pow_arr[pow_arr.size() - 1]) % C);
    }

    ll result = 1, target = 1;
    while(B != 0){
        target = (ll)log2(B); B -= (ll)pow(2, target);
        result = result * pow_arr[target] % C;
    }
    cout << result << '\n';

    return 0;
}