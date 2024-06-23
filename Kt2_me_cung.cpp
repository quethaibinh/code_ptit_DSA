#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
bool check;
vector<int> ke[100005];
int vis[100005];
int par[100005];
void input(){
    cin >> n >> m;
    check = false;
    for(int i = 1; i <= n; i ++) vis[i] = 0;
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u){
    vis[u] = 1;
    for(int i : ke[u]){
        if(vis[i] && par[u] != i) check = true;
        if(!vis[i]){
            par[i] = u;
            DFS(i);
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
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            if(!vis[i]) DFS(i);
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
        for(int i = 1; i <= n; i ++) ke[i].clear();
    }

    return 0;
}