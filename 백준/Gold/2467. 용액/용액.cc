#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int main() {
    fastIO(); solve(); return 0;
}

int N;

void solve() {    
    cin >> N;

    vector<int> v(N);
    for(auto& i : v) cin >> i;

    int front = 0, rear = N - 1;
    int r_front = -1, r_rear = -1, r_diff = INT_MAX;

    while(front < rear) {
        int diff = v[front] + v[rear];
        if(abs(diff) <= abs(r_diff)) { r_front = front; r_rear = rear; r_diff = diff; }

        if(abs(v[front]) > abs(v[rear])) front++;
        else rear--;
    }
    
    cout << v[r_front] << ' ' << v[r_rear];


}