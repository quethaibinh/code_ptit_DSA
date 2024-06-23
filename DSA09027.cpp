#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e, cnt;
vector<int> ke[1005];
int vis[1005];
void input(){
    cin >> v >> e;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u){
    vis[u] = cnt;
    for(int i : ke[u]){
        if(!vis[i]){
            DFS(i);
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
        cnt = 1;
        input();
        for(int i = 1; i <= v; i ++){
            if(!vis[i]){
                DFS(i);
                cnt ++;
            }
        }
        int t2; cin >> t2;
        while(t2 --){
            int x, y; cin >> x >> y;
            if(vis[x] == vis[y]) cout << "YES\n";
            else cout << "NO\n";
        }
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}