#include<bits/stdc++.h>

using namespace std;
#define ll long long
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;

int n, m, s;
vector<ii> ke[1005];
int vis[1005];
int d[1005];

void input(){
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i ++){
        vis[i] = 0;
        d[i] = 1e9;
        ke[i].clear();
    }
    for(int i = 1; i <= m; i ++){
        int u, v, w; cin >> u >> v >> w;
        ke[u].push_back({v, w});
        ke[v].push_back({u, w});
    }
}

void dijkstra(int s){
    d[s] = 0; // luu duong di 
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({d[s], s});
    while(!q.empty()){
        ii tmp = q.top(); q.pop();
        int dis = tmp.first;
        int u = tmp.second;
        if(dis > d[u]) continue;
        for(ii i : ke[u]){
            int v = i.first;
            int w = i.second;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        cout << d[i] << ' ';
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
        dijkstra(s);
        cout << '\n';
    }

    return 0;
}