#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int testCase = 0; cin >> testCase;
    while(testCase--){
        int oper = 0; cin >> oper;
        if(oper != 0){ pq.push(make_pair(abs(oper), oper)); continue; }

        if(pq.size() != 0){ cout << pq.top().second << '\n'; pq.pop(); }
        else cout << 0 << '\n';
    }

    return 0;
}