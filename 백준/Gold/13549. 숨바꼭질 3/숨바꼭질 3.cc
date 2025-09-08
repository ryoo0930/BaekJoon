#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }


int main(){
    fast_io();
    int N, K; cin >> N >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(100001, false);

    pq.push(make_pair(0, N));
    while(!pq.empty()){
        pair<int, int> current = pq.top(); pq.pop();
        int currentTime = current.first, currentIndex = current.second;
        visited[currentIndex] = true;

        if(currentIndex == K) { cout << currentTime << '\n'; break; }

        if((2 * currentIndex <= 100001) && !visited[2 * currentIndex]) { pq.push(make_pair(currentTime, 2 * currentIndex)); }
        if(currentIndex - 1 >= 0 && !visited[currentIndex - 1]) { pq.push(make_pair(currentTime + 1, currentIndex - 1)); }
        if(currentIndex + 1 <= 100001 && !visited[currentIndex + 1]) { pq.push(make_pair(currentTime + 1, currentIndex + 1)); }
    }
    
    return 0;
}