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

void duyetGiua(node* root, vector<int> &v){
    if(root == NULL) return;
    duyetGiua(root->left, v);
    v.push_back(root->val);
    duyetGiua(root->right, v);
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
        node* root1 = NULL;
        for(int i = 1; i <= n; i ++){
            int u, v; cin >> u >> v;
            char c; cin >> c;
            if(root1 == NULL) root1 = new node(u);
            insertNode(root1, u, v, c); 
        }
        int m; cin >> m;
        node* root2 = NULL;
        for(int i = 1; i <= m; i ++){
            int u, v; cin >> u >> v;
            char c; cin >> c;
            if(root2 == NULL) root2 = new node(u);
            insertNode(root2, u, v, c);
        }
        bool check = true;
        vector<int> check1, check2;
        duyetGiua(root1, check1);
        duyetGiua(root2, check2);
        if(check1.size() != check2.size()) check = false;
        for(int i = 0; i < check1.size(); i ++){
            // cout << check1[i] << ' ';
            if(check1[i] != check2[i]){
                check = false;
                break;
            }
        }
        if(check) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}