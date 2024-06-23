#include<bits/stdc++.h>

using namespace std;
#define ll long long
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;

int a, b, c;
char kg[33][33][33];
int vis[33][33][33];
int zs, xs, ys;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int dz[2] = {-1, 1};

void input(){
    cin >> a >> b >> c;
    for(int i = 1; i <= a; i ++){
        for(int j = 1; j <= b; j ++){
            for(int k = 1; k <= c; k ++){
                cin >> kg[i][j][k];
                if(kg[i][j][k] == 'S'){
                    zs = i; xs = j; ys = k;
                }
                vis[i][j][k] = 0;
            }
        }
    }
}

void BFS(int z, int x, int y){
    queue<pair<ii, ii>> q;
    q.push({{0, z}, {x, y}});
    vis[z][x][y] = 1;
    while(!q.empty()){
        pair<ii, ii> tmp = q.front(); q.pop();
        if(kg[tmp.first.second][tmp.second.first][tmp.second.second] == 'E'){
            cout << tmp.first.first << '\n';
            return;
        }
        for(int i = 0; i < 4; i ++){
            int xc = tmp.second.first + dx[i];
            int yc = tmp.second.second + dy[i];
            int zc = tmp.first.second;
            int steps = tmp.first.first;
            if(xc > 0 && xc <= b && yc > 0 && yc <= c && kg[zc][xc][yc] != '#' && vis[zc][xc][yc] != 1){
                vis[zc][xc][yc] = 1;
                q.push({{steps + 1, zc}, {xc, yc}});
            } 
        }
        for(int i = 0; i < 2; i ++){
            int zc = tmp.first.second + dz[i];
            int yc = tmp.second.second;
            int xc = tmp.second.first;
            int steps = tmp.first.first;
            if(zc > 0 && zc <= a && kg[zc][xc][yc] != '#' && vis[zc][xc][yc] != 1){
                vis[zc][xc][yc] = 1;
                q.push({{steps + 1, zc}, {xc, yc}});
            }
        }
    }
    cout << -1 << '\n';
    return;
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
        BFS(zs, xs, ys);
    }

    return 0;
}