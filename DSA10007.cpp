#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m, s;
vector<int> ke[1005];
vector<pair<int, int>> canh;
int vis[1005];

void input(){
    cin >> n >> m >> s;
    canh.clear();
    for(int i = 1; i <= n; i ++){
        ke[i].clear();
        vis[i] = 0;
    }
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u){
    vis[u] = 1;
    for(int i : ke[u])
        if(!vis[i]) DFS(i);
}

void BFS(int u){
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        for(int i : ke[tmp]){
            if(!vis[i]){
                vis[i] = 1;
                canh.push_back({tmp, i});
                q.push(i);
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

    int t; cin >> t;
    while(t --){
        input();
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            if(!vis[i]){
                DFS(i);
                cnt ++;
            }
        }
        if(cnt == 1){
            for(int i = 1; i <= n; i ++) vis[i] = 0;
            BFS(s);
            for(auto x : canh) cout << x.first << ' ' << x.second << '\n';
        }
        else cout << -1 << '\n';
    }

    return 0;
}