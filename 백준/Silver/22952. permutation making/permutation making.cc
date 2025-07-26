#include <iostream>
#include <vector>

using namespace std;

void fastIO() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    int N = 0; cin >> N;

    vector<int> arr;
    for (int i = 0; i < N / 2; i++) {
        arr.push_back(N - i);
        arr.push_back(i + 1);
    }
    if (N % 2 != 0) arr.push_back((N / 2) + 1);

    for (auto i : arr) cout << i << ' ';

    return 0;
}
