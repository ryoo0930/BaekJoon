#include <bits/stdc++.h>
using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

int fun1(int num, int P);

int main(){
    fast_io();
    int A = 0, P = 0; cin >> A >> P;
    unordered_map<int, bool> visited;
    vector<int> result;

    int targetNum = A;
    while(true){
        if(visited[targetNum] == true) break;
        visited[targetNum] = true;
        result.push_back(targetNum);

        targetNum = fun1(targetNum, P);
    }

    int count = 0;
    for(auto i : result){
        if(i == targetNum) break;
        count++;
    }
    cout << count;

    return 0;
}


int fun1(int num, int P){
    int sum = 0;
    while(num != 0){ 
        int digit = num % 10;
        sum += (int)pow(digit, P);
        num = num / 10;
    }
    return sum;
}