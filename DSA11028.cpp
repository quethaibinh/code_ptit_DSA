#include<bits/stdc++.h>

using namespace std;
#define ll long long
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;

int n;
int ans;
vector<int> ke[100005];
int vis[100005];

void input(){
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i ++){
        ke[i].clear();
        vis[i] = 0;
    }
    for(int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}

void BFS(int u){
    queue<ii> q;
    vis[u] = 1;
    q.push({u, 0});
    while(!q.empty()){
        ii tmp = q.front(); q.pop();
        ans = max(ans, tmp.second);
        for(int i : ke[tmp.first]){
            if(!vis[i]){
                vis[i] = 1;
                q.push({i, tmp.second + 1});
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
        BFS(1);
        cout << ans << '\n';
    }

    return 0;
}