#include <bits/stdc++.h>

using namespace std;
int L, C;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void DFS(vector<char>& arr, vector<char>& result, int startIndex);
bool checkVowels(char c);

int main()
{
    fast_io();
    cin >> L >> C;

    vector<char> arr(C);
    for(auto& i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    vector<char> result;

    DFS(arr, result, 0);

    return 0;
}

void DFS(vector<char>& arr, vector<char>& result, int startIndex){
    if(result.size() == L){
        int vowels = 0, consonants = 0;
        for(auto i : result) { if (checkVowels(i)) vowels++; else consonants++; }

        if(vowels >= 1 && consonants >= 2) { for(auto i : result) cout << i; cout << '\n'; }
        return;
    }
    for(int i = startIndex; i < C; i++){
        result.push_back(arr[i]);
        DFS(arr, result, i + 1);
        result.pop_back();
    }
}

bool checkVowels(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}
