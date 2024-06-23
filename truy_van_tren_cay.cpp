#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[100005];
int d[100005];
int check[100005];
struct node{
    int val;
    int inx;
    node* left;
    node* right;
    node(int x, int i){
        val = x;
        inx = i;
        left = right = NULL;
    }
};

void insertNode(node* &root, int x, int val, int i){
    if(x == root->inx){
        if(root->left == NULL) root->left = new node(val, i);
        else if(root->right == NULL) root->right = new node(val, i);
    }
    if(root->left != NULL) insertNode(root->left, x, val, i);
    if(root->right != NULL) insertNode(root->right, x, val, i);
}

void duyet(node* root){
    if(root == NULL) return;
    check[root->inx] = 1;
    for(int i = 1; i <= n; i ++){
        if(check[i] && a[i] < root->val){
            d[i] ++;
        }
    }
    duyet(root->left);
    duyet(root->right);
    check[root->inx] = 0;
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

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    node* root = new node(a[1], 1);
    for(int i = 2; i <= n; i ++){
        int x; cin >> x;
        insertNode(root, x, a[i], i);
    }
    // inorder(root);
    duyet(root);
    for(int i = 1; i <= n; i ++) cout << d[i] << '\n';

    return 0;
}