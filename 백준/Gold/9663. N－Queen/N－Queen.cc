#include <bits/stdc++.h>

using namespace std;

int N;
int result = 0;
void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void DFS(vector<int>& arr, int current_row);
bool checkQueen(vector<int>& arr, int target_index);

int main()
{
    cin >> N;
    vector<int> arr(N); // current_row is index, current_col is value
    DFS(arr, 0);

    cout << result << '\n';

    return 0;
}


void DFS(vector<int>& arr, int current_row){
    if(current_row == N){ result++; return; }
    for(int i = 0; i < N; i++){
        arr[current_row] = i;
        if(checkQueen(arr, current_row)){ DFS(arr, current_row + 1); }
    }
}

bool checkQueen(vector<int>& arr, int target_row){
    int target_col = arr[target_row];
    for(int i = 0; i < target_row; i++){
        if(arr[i] == target_col || target_row - i == abs(arr[i] - target_col)) return false;
    }
    return true;
}