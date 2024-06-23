#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
vector<int> ke[1005];
int vis[1005], vis2[1005];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
    }
}

void DFS(int u){
    vis2[u] = 1;
    for(int i : ke[u])
        if(!vis2[i]) DFS(i);
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    input();
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        for(int j : ke[i])
            vis[j] = 1;
    }
    for(int i = 1; i <= n; i ++)
        if(!vis[i]){
            cnt ++;
            DFS(i);
        }
    for(int i = 1; i <= n; i ++){
        if(!vis2[i]){
            DFS(i);
            cnt ++;
        }
    }
    cout << cnt;

    return 0;
}