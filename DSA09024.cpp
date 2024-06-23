#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e, u;
int vis[1005];
vector<int> ke[1005];
void input(){
    cin >> v >> e >> u;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}
void BFS(int u){
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    cout << u << ' ';
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int xx : ke[x]){
            if(!vis[xx]){
                cout << xx << ' ';
                q.push(xx);
                vis[xx] = 1;
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
        BFS(u);
        cout << '\n';
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}