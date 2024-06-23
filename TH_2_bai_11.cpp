#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> ke(1005);
int par[1005];

void DFS(int u){
    for(int i : ke[u]){
        if(par[i] == 0){
            par[i] = u;
            DFS(i);
        }
    }
}

void tracing(int i){
    if(par[i] == 0){
        cout << -1 << '\n';
        return;
    }
    int cur = i;
    vector<int> path;
    while(cur != 1){
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for(int i : path) cout << i << ' ';
    cout << '\n';
}

void BFS(int u){
    queue<int> q;
    vector<int> trace(n + 1);
    trace[u] = -1;
    q.push(u);
    while(!q.empty()){
        int cur = q.front(); 
        q.pop();
        for(int v : ke[cur]){
            if(trace[v] == 0){
                q.push(v);
                trace[v] = cur;
            }
        }
    }
    if(trace[1] == 0){
        cout << -1 << '\n';
        return;
    }
    vector<int> path;
    int cur = 1;
    while(cur != u){
        path.push_back(cur);
        cur = trace[cur];
    }
    path.push_back(u);
    reverse(path.begin(), path.end());
    for(int i : path) cout << i << ' ';
    cout << '\n';
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);      

    cin >> n >> m;
    // cout << n << ' ' << m;
    for(int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        // cout << x << ' ' << y << '\n';
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    // for(int i = 1; i <= n; i ++){
    //     for(int j : ke[i]) cout << j << ' ';
    // }
    par[1] = -1;
    DFS(1);
    // cout << 's';
    for(int i = 2; i <= n; i ++){
        tracing(i);
        BFS(i);
    }

    return 0;
}