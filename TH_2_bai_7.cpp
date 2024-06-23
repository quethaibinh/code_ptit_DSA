#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
int a[1005][1005];
int vis[1005][1005];
bool inside(int x, int y){
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void BFS(int x, int y){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++) vis[i][j] = -1;
    }
    vis[x][y] = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        if(tx < n) {
            int xx = tx + abs(a[tx][ty] - a[tx + 1][ty]);
            if(inside(xx, ty) && vis[xx][ty] == -1){
                vis[xx][ty] = vis[tx][ty] + 1;
                q.push({xx, ty});
            }
        }
        if(ty < m){
            int yy = ty + abs(a[tx][ty] - a[tx][ty + 1]);
            if(inside(tx, yy) && vis[tx][yy] == -1){
                vis[tx][yy] = vis[tx][ty] + 1;
                q.push({tx, yy});
            }
        }
        if(tx < n && ty < m){
            int xx = tx + abs(a[tx][ty] - a[tx + 1][ty + 1]);
            int yy = ty + abs(a[tx][ty] - a[tx + 1][ty + 1]);
            if(inside(xx, yy) && vis[xx][yy] == -1){
                vis[xx][yy] = vis[tx][ty] + 1;
                q.push({xx, yy});
            }
        }
    }
    cout << vis[n][m];
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
        cin >> n >> m;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++) cin >> a[i][j];
        }
        BFS(1, 1);
        cout << '\n';
    }

    return 0;
}