#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int k, n, m;
int kc[1005];
vector<int> ke[1005];
int vis[1005];
int par[1005];

void input(){
    cin >> k >> n >> m;
    for(int i = 1; i <= n; i ++) ke[i].clear();
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= k; i ++) cin >> kc[i];
    for(int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        ke[v].push_back(u);
    }
}

void DFS(int u){
    vis[u] = 1;
    for(int i : ke[u])
        if(!vis[i]) DFS(i);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    input();
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) vis[j] = 0;
        DFS(i);
        int cnt = 0;
        for(int j = 1; j <= k; j ++)
            if(vis[kc[j]]) cnt ++;
        if(cnt == k) ans ++;
        // cout << cnt << '\n';
    }
    cout << ans <<'\n';

    return 0;
}