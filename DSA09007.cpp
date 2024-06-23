#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e, s, t;
int vis[1005], par[1005];
vector<int> ke[1005];
void input(){
    cin >> v >> e >> s >> t;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void BFS(int u){
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int xx : ke[x]){
            if(!vis[xx]){
                par[xx] = x;
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

    int t1; cin >> t1;
    while(t1 --){
        bool check = true;
        input();
        BFS(s);
        if(vis[s] != vis[t]) check = false;
        if(!check) cout << -1;
        else{
            vector<int> d;
            while(t != s){
                d.push_back(t);
                t = par[t];
            }
            d.push_back(s);
            for(int i = d.size() - 1; i >= 0; i --) cout << d[i] << ' ';
        }
        cout << '\n';
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}