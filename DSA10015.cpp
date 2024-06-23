#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
int par[1005];
struct canh{
    int u, v, w;
};

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

vector<canh> ke;
void input(){
    cin >> n >> m;
    ke.clear();
    for(int i = 1; i <= m; i ++){
        int x, y, z; cin >> x >> y >> z;
        ke.push_back({x, y, z});
        ke.push_back({y, x, z});
    }
    init();
}

bool cmp(canh a, canh b){
    return a.w < b.w;
}

void kruskal(){
    int ans = 0;
    sort(ke.begin(), ke.end(), cmp);
    for(int i = 0; i < ke.size(); i ++){
        if(Union(ke[i].u, ke[i].v)){
            ans += ke[i].w;
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
        kruskal();
    }

    return 0;
}