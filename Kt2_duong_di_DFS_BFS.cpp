#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, m;
vector<int> ke[1005];
int vis[1005], checklt[1005], vis2[1005];
int par1[1005], par2[1005];
void input(){
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u, int cnt){
    vis[u] = 1;
    checklt[u] = cnt;
    for(int i : ke[u]){
        if(!vis[i]){
            par1[i] = u;
            DFS(i, cnt);
        }
    }
}

void BFS(int u){
    vis2[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int tmp = q.front(); q.pop();
        for(int i : ke[tmp]){
            if(!vis2[i]){
                par2[i] = tmp;
                vis2[i] = 1;
                q.push(i);
            }
        }
    }
}

void duongDiDFS(int u, int v){
    vector<int> vc;
    vc.push_back(v);
    while(u != par1[v]){
        v = par1[v];
        vc.push_back(v);
    }
    vc.push_back(u);
    for(int i = vc.size() - 1; i >= 0; i --) cout << vc[i] << ' ';
    cout << '\n';
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
        if(!vis[i]){
            DFS(i, cnt);
            cnt ++;
        }
    }
    for(int i = 2; i <= n; i ++){
        if(checklt[1] == checklt[i]){
            duongDiDFS(1, i);
            for(int j = 1; j <= n; j ++) vis2[j] = 0;
            for(int j = 1; j <= n; j ++) par2[j] = 0;
            BFS(i);
            vector<int> vc;
            vc.push_back(1);
            int x = 1;
            while(i != par2[x]){
                x = par2[x];
                vc.push_back(x);
            }
            vc.push_back(i);
            for(int j = vc.size() - 1; j >= 0; j --) cout << vc[j] << ' ';
        }
        else cout << -1;
        cout << '\n';
    }

    return 0;
}