#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
int duodi[1005][1005];
int vis[1005][1005];
pair<int, int> par[1005][1005];
void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> duodi[i][j];
            vis[i][j] = 0;
            par[i][j] = {0, 0};
        }
    }
}

void BFS(int i, int j){
    queue<pair<int, int>> q;
    vis[i][j] = 1;
    q.push({i, j});
    int cnt = 0;
    while(!q.empty()){
        pair<int, int> pa = q.front(); q.pop();
        int i1 = pa.first;
        int j1 = pa.second;
        if(i1 + duodi[i1][j1] <= n && !vis[i1 + duodi[i1][j1]][j1]){
            q.push({i1 + duodi[i1][j1], j1});
            vis[i1 + duodi[i1][j1]][j1] = 1;
            par[i1 + duodi[i1][j1]][j1] = {i1, j1}; 
        }
        if(j1 + duodi[i1][j1] <= m && !vis[i1][j1 + duodi[i1][j1]]){
            q.push({i1, j1 + duodi[i1][j1]});
            vis[i1][j1 + duodi[i1][j1]] = 1;
            par[i1][j1 + duodi[i1][j1]] = {i1, j1};
        }
    }
    pair<int, int> pa = {n, m};
    if(par[n][m].first == 0 || par[n][m].second == 0) cout << -1;
    else{
        while(pa.first != 1 || pa.second != 1){
            // cout << pa.first << ' ' << pa.second << '\n';
            pa = par[pa.first][pa.second];
            cnt ++;
        }
        cout << cnt;
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
        BFS(1, 1);
        cout << '\n';
    }

    return 0;
}