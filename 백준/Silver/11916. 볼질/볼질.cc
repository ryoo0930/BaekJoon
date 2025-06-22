#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main()
{   
    int N; cin >> N;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        int temp = 0; cin >> temp;
        q.push(temp);
    }

    int check_ball = 0;
    int arr[4] = { 0 };
    for (int i = 0; i < N; i++) {
        int op = q.front(); q.pop();
        if (op == 1 || op == 3) check_ball++;

        if ((check_ball == 4 || op == 2) && op != 3) {
            if (arr[3] == 1) { if (arr[1] == 1 && arr[2] == 1) { arr[3] = 0; arr[0]++; } }
            if (arr[2] == 1) { if (arr[1] == 1) { arr[3] = 1; arr[2] = 0; } }
            if (arr[1] == 1) { arr[2] = 1; arr[1] = 0; }
            arr[1] = 1;
            check_ball = 0; continue;
        }
        if (op == 3) {
            if (arr[3] == 1) { arr[3] = 0; arr[0]++; }
            if (arr[2] == 1) { arr[2] = 0; arr[3] = 1; }
            if (arr[1] == 1) { arr[1] = 0; arr[2] = 1; }
            if (check_ball == 4) { arr[1] = 1; check_ball = 0; continue; }
        }
    }

    cout << arr[0];

    return 0;
}