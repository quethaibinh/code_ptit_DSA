#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
char a[105][105];
int vis[105][105];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void BFS(int u, int v){
    a[u][v] = '.';
    queue<ii> q;
    q.push({u, v});
    while(!q.empty()){
        ii tmp = q.front(); q.pop();
        for(int i = 0; i < 8; i ++){
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= m && a[x][y] == 'W'){
                a[x][y] = '.';
                q.push({x, y});
            }
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

    cin >> n >> m;
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i][j] == 'W'){
                BFS(i, j);
                cnt ++;
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}