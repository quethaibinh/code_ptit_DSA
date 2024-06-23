#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

void makeNode(node* root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(root->val == u) makeNode(root, u, v, c);
    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
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
        set<int> se;
        for(int i = 1; i <= n; i ++){
            int u, v; cin >> u >> v;
            char c; cin >> c;
            se.insert(u);
            se.insert(v);
        }
        for(auto x : se) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}