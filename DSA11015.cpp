#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

ll ans;
struct node{
    ll val;
    node* left;
    node* right;
    node(ll x){
        val = x;
        left = right = NULL;
    }
};

void makeNode(node* root, ll u, ll v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insertNode(node* root, ll u, ll v, char c){
    if(root == NULL) return;
    if(root->val == u) makeNode(root, u, v, c);
    insertNode(root->left, u, v, c);
    insertNode(root->right, u, v, c);
}

ll maxSum(node* root){
    if(root == NULL) return 0;
    ll d1 = maxSum(root->left);
    ll d2 = maxSum(root->right);
    // neu la nut la thi khong phai cap nhat ans
    if(root->left !=NULL && root->right != NULL) ans = max(ans, d1 + d2 + root->val);
    root->val = max(d1, d2) + root->val;
    return root->val;
}

void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
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
        ans = -1e18;
        for(int i = 1; i <= n; i ++){
            ll u, v; cin >> u >> v;
            char c; cin >> c;
            if(root == NULL) root = new node(u);
            insertNode(root, u, v, c);
        }
        ll x = maxSum(root);
        cout << ans << '\n';
        // postOrder(root);
        // cout << '\n';
    }

    return 0;
}