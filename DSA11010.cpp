#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

bool check;
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
    if(u == root->val) makeNode(root, u, v, c);
    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

void checkFullTree(node* root){
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)){
        check = false;
        return;
    }
    if(root->left != NULL) checkFullTree(root->left);
    if(root->right != NULL) checkFullTree(root->left); 
}

set<int> se;
void checkNode(node* root, int count){
    if(root->left == NULL && root->right == NULL) se.insert(count);
    if(root->left != NULL) checkNode(root->left, count + 1);
    if(root->right != NULL) checkNode(root->right, count + 1);
}

void duyetGiua(node* root){
    if(root == NULL) return;
    duyetGiua(root->left);
    cout << root->val << ' ';
    duyetGiua(root->right);
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
        node* root = NULL;
        for(int i = 1; i <= n; i ++){
            int u, v; cin >> u >> v;
            char c; cin >> c;
            if(root == NULL) root = new node(u);
            insertNode(root, u, v, c);
        }
        // duyetGiua(root);
        check = true;
        checkFullTree(root);
        if(check){
            checkNode(root, 0);
            if(se.size() > 1) check = false;
            se.clear();
        }
        if(check) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}