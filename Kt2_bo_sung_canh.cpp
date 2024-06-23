#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
vector<int> ke[100005];
int vis[100005];

void input(){
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u, int &cnt){
    vis[u] = 1;
    cnt ++;
    for(int i : ke[u]){
        if(!vis[i]){
            DFS(i, cnt);
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
    int lt = 0;
    map<int, int> mp;
    for(int i = 1; i <= n; i ++){
        if(!vis[i]){
            int cnt = 0;
            DFS(i, cnt);
            mp[lt] = cnt;
            lt ++;
        }
    }
    int ans = 0;
    for(int i = 1; i < lt; i ++){
        ans = max(ans, mp[i]);
    }
    cout << ans + mp[0];

    return 0;
}