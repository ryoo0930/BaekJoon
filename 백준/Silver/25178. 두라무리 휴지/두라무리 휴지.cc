#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;

bool check_first_last(string str1, string str2, int size);
bool check_same_count(string str1, string str2, int size);
bool check_inside(string str1, string str2, int size);
int main()
{   
    string str1, str2;
    int size;
    cin >> size >> str1 >> str2;
    
    bool is_duramuri = false;

    is_duramuri = check_first_last(str1, str2, size) && check_inside(str1, str2, size) && check_same_count(str1, str2, size);
    if (is_duramuri) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

bool check_first_last(string str1, string str2, int size) {
    if (str1[0] != str2[0]) return false;
    if (str1[size - 1] != str2[size - 1]) return false;
    return true;
}
bool check_same_count(string str1, string str2, int size) {
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for (int i = 0; i < size; i++) {
        freq1[str1[i] - 'a']++;
        freq2[str2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) if (freq1 != freq2) return false;
    return true;
}
bool check_inside(string str1, string str2, int size) {
    stack<char> s1, s2;
    for (int i = 0; i < size; i++) {
        char c1 = str1[i], c2 = str2[i];
        if (string("aeiou").find(c1) == -1) { s1.push(c1); }
        if (string("aeiou").find(c2) == -1) { s2.push(c2); }

    }

    if (s1.size() != s2.size()) return false;
    int len = s1.size();
    for (int i = 0; i < len; i++) {
        if (s1.top() != s2.top()) return false;
        s1.pop(); s2.pop();
    }
    return true;
}