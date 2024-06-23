#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int par[1005];
void Init(int n){
    for(int i = 1; i <= n; i ++){
        par[i] = i;
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
    par[u] = v;
    return true;
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
        int v, e; cin >> v >> e;
        Init(v);
        bool check = false;
        for(int i = 1; i <= e; i ++){
            int x, y; cin >> x >> y;
            if(Union(x, y)) continue;
            else check = true;
        }
        cout << (check ? "YES\n": "NO\n");
    }

    return 0;
}