#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
int d[105][105];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= m; i ++){
        int u, v, w; cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
}

void floy(){
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
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

    input();
    floy();
    int q; cin >> q;
    while(q --){
        int u, v; cin >> u >> v;
        cout << d[u][v] << '\n';
    }

    return 0;
}