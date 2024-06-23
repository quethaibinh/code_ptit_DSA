#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int cnt;
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

void insertNode(node* &root, int x){
    if(root == NULL){
        root = new node(x);
        return;
    }
    if(x < root->val) insertNode(root->left, x);
    else insertNode(root->right, x);
}

void checkNode(node* &root){
    if(root == NULL) return;
    if(root->left != NULL || root->right != NULL) cnt ++;
    checkNode(root->left);
    checkNode(root->right);
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
        cnt = 0;
        node* root = NULL;
        for(int i = 1; i <= n; i ++){
            int x; cin >> x;
            insertNode(root, x);
        }
        checkNode(root);
        cout << cnt << '\n';
    }

    return 0;
}