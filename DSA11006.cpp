#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
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
    if(root->val == u) makeNode(root, u, v, c);
    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

void spiralOrder(node *root){
    stack<node*> rtl;
    stack<node*> ltr;
    ltr.push(root);
    while(!ltr.empty() || !rtl.empty()){
        while(!rtl.empty()){
            node* tmp = rtl.top(); rtl.pop();
            cout << tmp->val << ' ';
            if(tmp->left != NULL) ltr.push(tmp->left);
            if(tmp->right != NULL) ltr.push(tmp->right);
        }
        while(!ltr.empty()){    
            node* tmp = ltr.top(); ltr.pop();
            cout << tmp->val << ' ';
            if(tmp->right != NULL) rtl.push(tmp->right);
            if(tmp->left != NULL) rtl.push(tmp->left);
        }
    }
}

void duyetTruoc(node *root){
    if(root != NULL){
        duyetTruoc(root->left);
        cout << root->val << ' ';
        duyetTruoc(root->right);
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
            int u, v; cin >> u >> v;
            char c; cin >> c;
            if(root == NULL) root = new node(u);
            insertNode(root, u, v, c);
        }
        spiralOrder(root);
        // duyetTruoc(root);
        cout << '\n';
    }

    return 0;
}