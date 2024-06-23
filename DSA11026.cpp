#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int a[1000005];
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = right = NULL;
    }
};

void insertNode(node* &root, int startt, int endd){
    if(startt > endd) return;
    int mid = (startt + endd) / 2;
    if(root == NULL) root = new node(a[mid]);
    insertNode(root->left, startt, mid - 1);
    insertNode(root->right, mid + 1, endd);
}

void postorder(node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
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
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n);
        insertNode(root, 0, n - 1);
        postorder(root);
        cout << '\n';
    }

    return 0;
}