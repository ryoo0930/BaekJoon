#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int main()
{
    int arrSize = 0; cin >> arrSize;
    vector<int> arr1(arrSize);
    vector<int> arr2(arrSize);

    for(auto& i : arr1) cin >> i;
    for(auto& i : arr2) cin >> i;

    int diff1 = 0, diff2 = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr1[i] > arr2[i]) diff1 += arr1[i] - arr2[i];
        else diff2 += arr2[i] - arr1[i];
    }

    if(diff1 < diff2) cout << diff1 << '\n';
    else cout << diff2 << '\n';


    return 0;
}