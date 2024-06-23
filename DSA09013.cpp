#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e;
int vis[1005];
vector<int> ke[1005];
vector<pair<int, int>> canh;
void input(){
    cin >> v >> e;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        canh.push_back({x, y});
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u, int d, int c){
    vis[u] = 1;
    for(int x : ke[u]){
        if((u == d && x == c) || (u == c && x == d)) continue;
        if(!vis[x]) DFS(x, d, c);
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
                DFS(i, -1, -1);
                cnt ++;
            }
        }
        for(int i = 0; i < e; i ++){
            memset(vis, 0, sizeof(vis));
            int cntCheck = 0;
            for(int j = 1; j <= v; j ++){
                if(!vis[j]){
                    DFS(j, canh[i].first, canh[i].second);
                    cntCheck ++;
                }
            }
            // if(cntCheck > cnt) cout << i + 1 << ' ';
            if(cntCheck > cnt) cout << canh[i].first << ' ' << canh[i].second << ' ';
        }
        for(int i = 1; i <= v; i ++) ke[i].clear();
        for(int i = 1; i <= e; i ++) canh.clear();
        cout << '\n';
    }

    return 0;
}