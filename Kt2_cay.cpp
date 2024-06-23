#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

struct Node{
    int val;
    Node *left, *right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

Node *bst(int a[], int s, int e){
    if(s > e) return NULL;
    int m = (s + e) / 2;
    Node *root = new Node(a[m]);
    root -> left = bst(a, s, m - 1);
    root -> right = bst(a, m + 1, e);
    return root;
}

void preOrder(Node *root){
    if(root == NULL) return;
    cout << root -> val << ' ';
    if(root -> right) preOrder(root -> right);
    if(root -> left) preOrder(root -> left);
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
        int a[n];
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n);
        Node *root = bst(a, 0, n - 1);
        preOrder(root);
        cout << '\n';
    }

    return 0;
}