#include<bits/stdc++.h>

using namespace std;
#define ll long long
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;

int n, m;
int a[505][505];
int vis[505][505];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
            vis[i][j] = 0;
        }
    }
}

void BFS(){
    queue<ii> q;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i][j] == 2){
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        ii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i ++){
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= m && a[x][y] == 1){
                a[x][y] = 2;
                vis[x][y] = vis[tmp.first][tmp.second] + 1;
                q.push({x, y});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i][j] == 1){
                cout << -1 << '\n';
                return;
            }
            ans = max(ans, vis[i][j]);
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
        BFS();
    }

    return 0;
}