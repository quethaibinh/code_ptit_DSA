#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

struct node{
    int val;
    node *left;
    node *right;
    node(int v){
        val = v;
        left = right = NULL;
    }
};

void makeNode(node *root, int u, int v, char c){
    if(c == 'L') root -> left = new node(v);
    else root -> right = new node(v);
}

void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root -> val == u) makeNode(root, u, v, c);
    insertNode(root -> left, u, v, c);
    insertNode(root -> right, u, v, c);
}

void duyetgiua(node *root){
    if(root != NULL){
        duyetgiua(root -> left);
        cout << root -> val << ' ';
        duyetgiua(root -> right);
    }
}

void level_order(node *root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front(); q.pop();
        cout << tmp->val << ' ';
        if(tmp->left != NULL) q.push(tmp->left);
        if(tmp->right != NULL) q.push(tmp->right);
    }
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
            int x, y; cin >> x >> y;
            char c; cin >> c;
            if(root == NULL){
                root = new node(x);
                makeNode(root, x, y, c);
            }
            else insertNode(root, x, y, c);
        }
        level_order(root);
        cout << '\n';
    }

    return 0;
}