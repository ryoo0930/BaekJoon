#include <iostream>

using namespace std;

void fastIO() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int main() {
    int testCase = 0; cin >> testCase;
    while (testCase--) {
        int A, B; cin >> A >> B;
        
        int startA = A, startB = B;
        while (true) {
            if (startA * 3 <= startB && startB <= startA * 4) break;
            if (startA * 3 < B) startA++;
            else startB = startA * 3;
        }

        cout << startA - A + startB - B << '\n';
    }



    return 0;
}
