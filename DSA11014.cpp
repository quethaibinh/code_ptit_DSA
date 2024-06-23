#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int ans;
struct node{
    int val;
    node* left;
    node* right;
    node(int v){
        val = v;
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

bool checkNode(node* root){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) return true;
    return false;
}

int sum(node* root){
    int res = 0; // tinh tong cua cac node right tai moi root
    if(root == NULL) return res;
    if(root->right != NULL && checkNode(root->right)) res = root->right->val;
    if(root->right != NULL) res += sum(root->right);
    if(root->left != NULL && !checkNode(root->left)) res += sum(root->left);
    return res;
}

// void duyet(node* root, int check){
//     if(root == NULL) return;
//     if(root->left == NULL && root->right == NULL && check == 2) ans += root->val;
//     if(root->right != NULL) duyet(root->right, 2);
//     if(root->left != NULL) duyet(root->left, 1);
// }

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
        ans = 0;
        node* root = NULL;
        for(int i = 1; i <= n; i ++){
            int u, v; cin >> u >> v;
            char c; cin >> c;
            if(root == NULL) root = new node(u);
            insertNode(root, u, v, c);
        }
        // duyet(root, 1);
        // cout << ans << '\n';
        cout << sum(root) << '\n';
    }

    return 0;
}