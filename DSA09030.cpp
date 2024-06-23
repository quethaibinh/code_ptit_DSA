#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
typedef pair<int, int> ii;

int v, e;
vector<int> ke[1005];
int color[1005];
bool check;
void input(){
    check = true;
    memset(color, 0, sizeof(color));
    cin >> v >> e;
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void BFS(int u){
    queue<int> q;
    color[u] = 1;
    q.push(u);
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j : ke[i]){
            if(!color[j]){
                color[j] = -color[i];
                q.push(j);
            }
            else{
                if(color[j] == color[i]){
                    check = false;
                    return;
                }
            }
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
        input();
        for(int i = 1; i <= v; i ++){
            if(!color[i]) BFS(i);
        }
        cout << (check ? "YES\n": "NO\n");
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}