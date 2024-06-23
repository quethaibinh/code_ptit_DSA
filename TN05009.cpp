#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e;
vector<int> ke[1005];
int vis[1005], par[1005];
vector<int> kq;
bool check;
void input(){
    cin >> v >> e;
    kq.clear();
    check = false;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= v; i ++) sort(ke[i].begin(), ke[i].end());
}

void DFS(int u){
    vis[u] = 1;
    if(!check) kq.push_back(u);
    for(int i : ke[u]){
        if(vis[i] && i != par[u]){
            if(!check && i == 1) {
                kq.push_back(i);
                check = true;
            }
        }
        if(!vis[i]){
            par[i] = u;
            DFS(i);
        }
    }
    if(!check) kq.pop_back();
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
        DFS(1);
        if(check && !kq.empty()){
            for(int x : kq) cout << x << ' ';
        }
        else cout << "NO";
        cout << '\n';
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}