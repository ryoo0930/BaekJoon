#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void fastIO() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    int N = 0; cin >> N;
    vector<int> v(N); for (auto& i : v) cin >> i;
    deque<int> result;
    
    for (int i = N - 1; i >= 0; i--) {
        int oper = v[i];
        int targetNumber = N - i;
        if (oper == 1) {
            result.push_front(targetNumber);
        }
        else if (oper == 2) {
            int temp = result.front(); result.pop_front();
            result.push_front(targetNumber);
            result.push_front(temp);
        }
        else if (oper == 3) {
            result.push_back(targetNumber);
        }
    }

    for (auto i : result) {
        cout << i << ' ';
    }
    return 0;
}
