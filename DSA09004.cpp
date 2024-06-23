#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e, u;
vector<int> ke[1005];
int vis[1005];
void input(){
    cin >> v >> e >> u;
    memset(vis, 0, sizeof(vis));
    vector<pair<int, int>> inp(e + 1);
    for(int i = 1; i <= e; i ++){
        cin >> inp[i].first >> inp[i].second;
        ke[inp[i].first].push_back(inp[i].second);
        ke[inp[i].second].push_back(inp[i].first);
    }
}

void DFS(int u){
    cout << u << ' ';
    vis[u] = 1;
    for(auto x : ke[u]){
        if(!vis[x]){
            DFS(x);
        }
    }
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
        DFS(u);
        cout << '\n';
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}