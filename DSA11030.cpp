#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
vector<int> ke[1005];
int vis[1005];
int par[1005];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        vis[i] = 0;
        par[i] = 0;
        ke[i].clear();
    }
    for(int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}

void BFS(int startt, int endd){
    int cnt = 0;
    vis[startt] = 1;
    queue<int> q;
    q.push(startt);
    bool check = false;
    int ii = startt;
    while(!q.empty()){
        if(check) break;
        int tmp = q.front(); q.pop();
        for(int i : ke[tmp]){
            if(!vis[i]){
                par[i] = tmp;
                vis[i] = 1;
                if(i == endd){
                    ii = i;
                    check = true;
                    break;
                }
                q.push(i);
            }
        }
    }
    while(ii != startt){
        cnt ++;
        ii = par[ii];
    }
    cout << cnt;
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
        int q; cin >> q;
        while(q --){
            int u, v; cin >> u >> v;
            for(int i = 1; i <= n; i ++){
                vis[i] = 0;
                par[i] = 0;
            }
            BFS(u, v);
            cout << '\n';
        }
    }

    return 0;
}