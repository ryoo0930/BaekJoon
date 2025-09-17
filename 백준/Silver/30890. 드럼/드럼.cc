#include <bits/stdc++.h>
using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
int gcd(int x, int y);

int main(){
    fast_io();
    int X, Y; cin >> X >> Y;
    int lcm = (X * Y) / gcd(X, Y);

    vector<int> result(lcm + 1, -1);
    for(int i = lcm / X; i <= lcm; i += lcm / X){ result[i] = 1; }
    for(int i = lcm / Y; i <= lcm; i += lcm / Y){
        if(result[i] == 1) { result[i] = 3; }
        else result[i] = 2; 
    }

    for(auto i : result){
        if(i == -1) continue;
        else cout << i;
    }


    return 0;
}

int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x % y);
}