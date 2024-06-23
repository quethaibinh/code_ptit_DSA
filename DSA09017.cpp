#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
vector<int> ke[1005];
int vis[1005];

void input(){
    cin >> n;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n - 1; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u){
    vis[u] = 1;
    for(int i : ke[u]){
        if(!vis[i]) DFS(i);
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
        cout << (cnt == 1 ? "YES\n": "NO\n");
        for(int i = 1; i <= n; i ++) ke[i].clear();
    }

    return 0;
}