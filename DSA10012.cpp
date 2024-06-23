#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> ke[1005];
int d[105][105];
vector<pair<int, int>> canh;

void input(){
    cin >> n >> m;
    canh.clear();
    for(int i = 1; i <= n; i ++){
        ke[i].clear();
        for(int j = 1; j <= n; j ++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = 1e9;
        }
    }
    for(int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        d[u][v] = 1;
        ke[u].push_back({v, 1});
        canh.push_back({u, v});
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

    int t; cin >> t;
    while(t --){
        input();
        floy();
        double ans = 0;
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(d[i][j] != 1e9 && d[j][i] != 1e9 && d[i][j] != 0){
                ans += (d[i][j] + d[j][i]);
                cnt += 2;
            }
            }
        }
        // cout << ans << ' ' << cnt << '\n';
        cout << fixed << setprecision(2) << ans / cnt << '\n';
    }

    return 0;
}