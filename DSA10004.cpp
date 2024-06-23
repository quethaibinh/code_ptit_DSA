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
        for(int i = 1; i <= v; i ++){
            if(!vis[i]){
                DFS(i);
                cnt ++;
            }
        }
        // cout << cnt << '\n';
        if(cnt != 1) cout << 0 << '\n';
        else{
            int check = 0;
            for(int i = 1; i <= v; i ++){
                if(ke[i].size() % 2 != 0) check ++;
            }
            if(check == 0) cout << 2 << '\n';
            else if(check <= 2) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}