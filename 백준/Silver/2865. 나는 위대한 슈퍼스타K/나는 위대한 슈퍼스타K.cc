#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
bool compare(pair<int, double>& a, pair<int, double>& b) { return a.second > b.second; }

int main()
{
    int N, M, K; cin >> N >> M >> K;
    vector<pair<int, double>> arr;
    vector<bool> used(N + 1, false);
    for(int i = 0; i < M; i++){
        for(int i = 0; i < N; i++){
            int number; cin >> number;
            double score; cin >> score;
            arr.push_back(make_pair(number, score));
        }
    }
    sort(arr.begin(), arr.end(), compare);


    double result = 0; int count = 0;
    for(int i = 0; i < M * N; i++){
        if(count == K) break;
        if(used[arr[i].first] == false) { used[arr[i].first] = true; result += arr[i].second; count++; }
    }
    
    cout << fixed << setprecision(1) << result;
    return 0;
}