#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main()
{
    fast_io();
    int N; cin >> N;
    stack<pair<int, int>> tower; // pairing (index, height)
    vector<int> answer;

    for(int i = 0; i < N; i++){
        int currentHeight = 0; cin >> currentHeight;
        
        while(!tower.empty() && tower.top().second < currentHeight){ tower.pop(); }
        if(tower.empty()) answer.push_back(0);
        else answer.push_back(tower.top().first);

        tower.push(make_pair(i + 1, currentHeight));
    }

    for(auto i : answer) cout << i << ' ';

    return 0;
}