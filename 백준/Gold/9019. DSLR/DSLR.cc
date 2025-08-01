#include <iostream>
#include <queue>
using namespace std;

void fastIO() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void BFS(int start, int target);

int main() {
    fastIO();
    int testCase; cin >> testCase;

    while(testCase--){
        int start = 0, target = 0; cin >> start >> target;
        BFS(start, target);
    }



    return 0;
}

void BFS(int start, int target) {
    queue<pair<int, string>> q;
    int visited[10000] = { 0 };

    q.push(make_pair(start, ""));
    visited[start] = true;

    while (!q.empty()) {
        int currentNum = q.front().first;
        string currentCommand = q.front().second;
        q.pop();

        if (currentNum == target) { cout << currentCommand << '\n'; return; }

        int next_D = (currentNum * 2) % 10000;
        if (!visited[next_D]) {
            visited[next_D] = true;
            q.push(make_pair(next_D, currentCommand + 'D'));
        }

        int next_S = (currentNum - 1 + 10000) % 10000;
        if (!visited[next_S]) {
            visited[next_S] = true;
            q.push(make_pair(next_S, currentCommand + 'S'));
        }

        int next_L = ((currentNum % 1000) * 10) + (currentNum / 1000);
        if (!visited[next_L]) {
            visited[next_L] = true;
            q.push(make_pair(next_L, currentCommand + 'L'));
        }

        int next_R = (currentNum / 10) + (currentNum % 10) * 1000;
        if (!visited[next_R]) {
            visited[next_R] = true;
            q.push(make_pair(next_R, currentCommand + 'R'));
        }
    }
}