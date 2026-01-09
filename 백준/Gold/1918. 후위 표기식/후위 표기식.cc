#include <bits/stdc++.h>

using namespace std;

void fastIO() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void solve();

int getRank(char c);

int main() {
    fastIO(); solve(); return 0;
}


void solve() {
    string input; cin >> input;
    stack<char> s; string result = "";

    for(char c : input) {
        if(isalnum(c)) { result.push_back(c); continue; }
        if(c == '(') { s.push(c); continue; }
        if(c == ')') { while(!s.empty() && s.top() != '(') { result.push_back(s.top()); s.pop(); } if(!s.empty()) s.pop(); continue; }
        
        while(!s.empty() && (getRank(s.top()) >= getRank(c))) { result.push_back(s.top()); s.pop(); }
        s.push(c);
    }
    while(!s.empty()) {result.push_back(s.top()); s.pop();}

    cout << result;
    
}

int getRank(char c) {
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}