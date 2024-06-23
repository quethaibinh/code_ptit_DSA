#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e;
vector<int> ke[1005];
int vis[1005];
void input(){
    cin >> v >> e;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
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
        for(int i = 1; i <= v; i ++){
            if(!vis[i]){
                cnt ++;
                DFS(i);
            }
        }
        if(cnt != 1) cout << 0 << '\n';
        else{
            int check = 0;
            int dc[v + 1], dt[v + 1];
            memset(dc, 0, sizeof(dc));
            memset(dt, 0, sizeof(dt));
            for(int i = 1; i <= v; i ++){
                dc[i] = ke[i].size();
                for(int j : ke[i]) dt[j] ++;
            }
            for(int i = 1; i <= v; i ++){
                if(dc[i] != dt[i]){
                    check = 1;
                    break;
                }
            }
            if(!check) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}