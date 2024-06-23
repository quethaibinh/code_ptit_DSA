#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
    
struct node{
    int val;
    node *left;
    node *right;
    node (int x){
        val = x;
        left = right = NULL;
    }
};

void makeNode(node *root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(u == root->val) makeNode(root, u, v, c);
    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

set<int> se;
void nodeTree(node *root, int count){
    if(root->left != NULL) nodeTree(root->left, count + 1);
    if(root->right != NULL) nodeTree(root->right, count + 1); 
    if(root->right == NULL && root->left == NULL) se.insert(count);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        node *root = NULL;
        for(int i = 1; i <= n; i ++){
            int u, v;
            char c;
            cin >> u >> v >> c;
            if(root == NULL) root = new node(u);
            insertNode(root, u, v, c);
        }
        nodeTree(root, 0);
        if(se.size() == 1) cout << 1 << '\n';
        else cout << 0 << '\n';
        se.clear();
    }

    return 0;
}