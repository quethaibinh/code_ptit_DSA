#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
#define ll long long
const int MOD = 1e9 + 7;

int n, k, m;
int cnt;
int a[105][105];
int vis[105][105];
map<pair<ii, ii>, int> rao;
vector<ii> cuu;

int dx[8] = {-1, 0, 1, 0};
int dy[8] = {0, 1, 0, -1};

void input(){
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i ++){
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        rao[{{u, v}, {x, y}}] ++;
    }
    for(int i = 1; i <= k; i ++){
        int u, v; cin >> u >> v;
        cuu.push_back({u, v});
    }
}

bool checkRao(int u, int v, int x, int y){
    if(rao[{{u, v}, {x, y}}] != 0 || rao[{{x, y}, {u, v}}] != 0) return true;
    return false;
}

bool checkCuu(int u, int v){
    for(auto x : cuu){
        if(u == x.first && v == x.second) return true;
    }
    return false;
}

void BFS(int u, int v){
    vis[u][v] = 1;
    queue<ii> q;
    q.push({u, v});
    while(!q.empty()){
        ii tmp = q.front(); q.pop();
        for(int i = 0; i < 4; i ++){
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= n && !vis[x][y]){
                if(!checkRao(tmp.first, tmp.second, x, y)){
                    if(checkCuu(x, y)) cnt ++;
                    vis[x][y] = 1;
                    q.push({x, y});
                }
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

    input();
    int ans = 0;
    for(auto x : cuu){
        cnt = 1;
        memset(vis, 0, sizeof(vis));
        BFS(x.first, x.second);
        ans += (k - cnt);
    }
    cout << ans / 2 << '\n';

    return 0;
}