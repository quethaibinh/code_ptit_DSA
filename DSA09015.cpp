#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e;
vector<int> ke[1005];
int vis[1005], par[1005];
bool check;

void input(){
    cin >> v >> e;
    check = false;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

void DFS(int u){
    vis[u] = 1;
    for(int i : ke[u]){
        if(vis[i] == 1 && par[u] != i){
            check = true;
        }
        if(vis[i] == 0){
            par[i] = u;
            DFS(i);
        }
    }
    vis[u] = 2;
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
        for(int i = 1; i <= v; i ++){
            if(vis[i] == 0) DFS(i);
        }
        cout << (check ? "YES\n": "NO\n");
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}