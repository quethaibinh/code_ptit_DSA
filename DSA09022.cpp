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
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

void DFS(int u){
    vis[u] = 1;
    cout << u << ' ';
    for(int x : ke[u]){
        if(!vis[x]) DFS(x);
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
        for(int i = 1; i <= v; i ++) ke[i].clear();
        cout << '\n';
    }

    return 0;
}