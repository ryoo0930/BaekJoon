#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void sieve(vector<bool>& check, long long min, long long max);

int main()
{
    long long min = 0, max = 0; cin >> min >> max;
    int result = 0; 
    vector<bool> check(max - min + 1, false);
    sieve(check, min, max);

    
    for(int i = 0; i < max - min + 1; i++){ if(!check[i]) result++; }
    cout << result;

    return 0;
}

void sieve(vector<bool>& check, long long min, long long max){

    for(long long i = 2; i * i <= max; i++){
        long long pow = i * i;
        long long startIndex = min / pow;

        for(long long j = startIndex; j * pow <= max; j++){
            if(j * pow >= min) { check[(j * pow) - min] = true; }
        }
    }
}