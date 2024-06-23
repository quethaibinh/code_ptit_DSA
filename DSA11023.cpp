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

void insertNode(node* &root, int x){
    if(root == NULL){
        root = new node(x);
        return;
    }
    if(x < root->val) insertNode(root->left, x);
    else insertNode(root->right, x);
}

int hight(node* &root){
    if(root == NULL) return -1; // do sau cua node null
    int d1 = hight(root->left) + 1;
    int d2 = hight(root->right) + 1;
    return max(d1, d2);
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
            int x; cin >> x;
            insertNode(root, x);
        }
        cout << hight(root) << '\n';
    }

    return 0;
}