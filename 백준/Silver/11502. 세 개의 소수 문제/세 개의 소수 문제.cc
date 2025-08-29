#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void sieve(vector<bool>& prime);

int main()
{
    vector<bool> prime (1000, true); prime[0] = false; prime[1] = false;
    sieve(prime);

    int testCase = 0; cin >> testCase;
    while(testCase--){
        int targetNumber = 0; cin >> targetNumber;
        bool flag = true;
        for(int i = 0; i <= targetNumber; i++){
            for(int j = 0; j <= targetNumber; j++){
                for(int k = 0; k <= targetNumber; k++){
                    if(prime[i] && prime[j] && prime[k] && i + j + k == targetNumber){
                        cout << i << ' ' << j << ' ' << k << '\n';
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) break;
        }

        if(flag) cout << '0' << '\n';


    }
    

    return 0;
}

void sieve(vector<bool>& prime){
    for(int i = 2; i < 1000; i++){
        if(prime[i] == false) continue;
        for(int j = i * 2; j < 1000; j += i){
            prime[j] = false;
        }
    }
}