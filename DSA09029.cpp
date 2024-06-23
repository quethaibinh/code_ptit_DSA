#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int v, e;
vector<int> ke[1005];
int vis[1005], check[1005];
bool kt;

void input(){
    cin >> v >> e;
    kt = false;
    memset(vis, 0, sizeof(vis));
    memset(check, 0, sizeof(check));
    for(int i = 1; i <= e; i ++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

// ham check chu trinh Hamilton
// void Hamilton(int u, int k){
//     for(int i : ke[u]){
//         if(k == v + 1){
//             if(check[1] == i) kt = true;
//         }
//         else{
//             if(!vis[i]){
//                 check[k] = i; vis[u] = 1;
//                 Hamilton(i, k + 1);
//                 vis[u] = 0;
//             }
//         }
//     }
// }

//ham check duong di Hamilton
void Hamilton(int u, int k){
    if(k == v) kt = true;
    if(kt) return;
    for(int i : ke[u]){
        if(!vis[i]){
            vis[i] = 1;
            Hamilton(i, k + 1);
            vis[i] = 0;
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
            vis[i] = 1;
            Hamilton(i, 1);
            if(kt) break;
        }
        cout << kt << '\n';
        for(int i = 1; i <= v; i ++) ke[i].clear();
    }

    return 0;
}