#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int par[100005];
int sz[100005];
void Init(int n){
    for(int i = 1; i <= n; i ++){
        par[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    while(u != par[u]){
        u = par[u];
    }
    return u;
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] <= sz[v]){
        sz[v] += sz[u];
        par[u] = v;
    }
    else{
        sz[u] += sz[v];
        par[v] = u;
    }
    return true;
}

void input(){
    int ans = 0;
    int n, m; cin >> n >> m;
    Init(n);
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        if(Union(x, y)){
            // cout << sz[par[x]] << ' ' << sz[par[y]] << '\n';
            ans = max(ans, max(sz[Find(x)], sz[Find(y)]));
        }
    }
    cout << ans << '\n';
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
    }

    return 0;
}