#include <bits/stdc++.h>

using namespace std;

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
void preorder(unordered_map<char, pair<char, char>> tree, char targetNode);
void inorder(unordered_map<char, pair<char, char>> tree, char targetNode);
void postorder(unordered_map<char, pair<char, char>> tree, char targetNode);

int main()
{
    fast_io();
    int NodeSize = 0; cin >> NodeSize;
    unordered_map<char, pair<char, char>> tree(NodeSize);
    for(int i = 0; i < NodeSize; i++){
        char parentNode, leftNode, rightNode; cin >> parentNode >> leftNode >> rightNode;
        tree[parentNode] = make_pair(leftNode, rightNode);
    }

    preorder(tree, 'A');
    cout << '\n';
    inorder(tree, 'A'); 
    cout << '\n';
    postorder(tree, 'A');

    return 0;
}

void preorder(unordered_map<char, pair<char, char>> tree, char targetNode){
    cout << targetNode;
    if(tree[targetNode].first != '.') preorder(tree, tree[targetNode].first);
    if(tree[targetNode].second != '.') preorder(tree, tree[targetNode].second);
}

void inorder(unordered_map<char, pair<char, char>> tree, char targetNode){
    if(tree[targetNode].first != '.') inorder(tree, tree[targetNode].first);
    cout << targetNode;
    if(tree[targetNode].second != '.') inorder(tree, tree[targetNode].second);
}
void postorder(unordered_map<char, pair<char, char>> tree, char targetNode){
    if(tree[targetNode].first != '.') postorder(tree, tree[targetNode].first);
    if(tree[targetNode].second != '.') postorder(tree, tree[targetNode].second);
    cout << targetNode;
}