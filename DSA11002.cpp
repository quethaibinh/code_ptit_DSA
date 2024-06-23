#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int sovle(int a, int b, string s){
    if(s == "+") return a + b;
    if(s == "-") return a - b;
    if(s == "*") return a * b;
    if(s == "/") return a / b;
}

struct node{
    string val;
    node* left;
    node* right;
    node(string x){
        val = x;
        left = right = NULL;
    }
};

int resovle(node* root){
    if(root->left == NULL && root->right == NULL) return stoi(root->val);
    int d1 = resovle(root->left);
    int d2 = resovle(root->right);
    return sovle(d1, d2, root->val);
}

// void inorder(node* root){
//     if(root == NULL) return;
//     inorder(root->left);
//     cout << root->val << ' ';
//     inorder(root->right);
// }

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
        vector<string> a;
        node* root = NULL;
        for(int i = 1; i <= n; i ++){
            string s; cin >> s;
            a.push_back(s);
        }
        queue<node*> q;
        root = new node(a[0]);
        q.push(root);
        for(int i = 1; i < n; i += 2){
            node* tmp = q.front(); q.pop();
            tmp->left = new node(a[i]);
            q.push(tmp->left);
            tmp->right = new node(a[i + 1]);
            q.push(tmp->right);
        }
        cout << resovle(root);
        // inorder(root);
        cout << '\n';
    }

    return 0;
}