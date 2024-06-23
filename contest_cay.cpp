#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

struct node{
    string val;
    node* left;
    node* right;
    node(string x){
        val = x;
        left = right = NULL;
    }  
};

void RNL(node* root){
    if(root == NULL) return;
    RNL(root->right);
    cout << root->val << ' ';
    RNL(root->left);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    cin.ignore();
    while(t --){
        string s;
        getline(cin, s);
        vector<string> v;
        queue<node*> q;
        string token;
        stringstream ss(s);
        while(ss >> token){
            v.push_back(token);
        }
        node* root = new node(v[0]);
        q.push(root);
        for(int i = 1; i < v.size(); i += 2){
            node* tmp = q.front(); q.pop();
            if(v[i] != "N"){
                tmp->left = new node(v[i]);
                q.push(tmp->left);
            }
            if(v[i + 1] != "N"){
                tmp->right = new node(v[i + 1]);
                q.push(tmp->right);
            }
        }
        RNL(root);
        cout << '\n';
    }

    return 0;
}