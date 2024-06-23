#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
vector<int> ke[1005];
int vis[1005];
int par[1005];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        vis[i] = 0;
        ke[i].clear();
    }
    for(int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
    }
}

void DFS(int u){
    vis[u] = 1;
    for(int i : ke[u]){
        if(!vis[i]){
            par[i] = u;
            DFS(i);
        }
    }
}

bool cmp(vector<int> &a, vector<int> &b){
    return a[a.size() - 1] < b[b.size() - 1];
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
        input();
        DFS(1);
        vector<vector<int>> v;
        for(int i = 1; i <= n; i ++){
            if(ke[i].size() == 0){
                int ii = i;
                vector<int> duong;
                while(ii != 1){
                    duong.push_back(ii);
                    ii = par[ii];
                }
                duong.push_back(1);
                reverse(duong.begin(), duong.end());
                v.push_back(duong);
            }
        }
        sort(v.begin(), v.end(), cmp);
        for(auto x : v){
            for(auto y : x) cout << y << ' ';
            cout << '\n';
        }
    }

    return 0;
}