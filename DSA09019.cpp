#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
int par[1005];

void init(){
    for(int i = 1; i <= n; i ++) par[i] = i;
}

int find(int u){
    while(u != par[u]){
        u = par[u];
    }
    return u;
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    par[u] = v;
    return true;
}

void input(){
    bool check = false;
    cin >> n >> m;
    init();
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        if(!Union(x, y)) check = true;
    }
    if(check) cout << "YES\n";
    else cout << "NO\n";
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
        // for(int i = 1; i <= n; i ++) cout << par[i] << '\n';
    }

    return 0;
}