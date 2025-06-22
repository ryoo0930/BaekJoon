#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{   
    long long n, m; cin >> n >> m;
    long long result = 0;
    result += ((m - 1) * n) + ((n - 1) * m);
    result += 2 * ((m - 1) * (n - 1));
    cout << result;
    return 0;
}