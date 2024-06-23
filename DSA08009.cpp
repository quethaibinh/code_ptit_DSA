#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int vis[10005];
void BFS(int s, int t){
    queue<pair<int, ll>> q;
    q.push({s, 0});
    vis[s] = 1;
    while(!q.empty()){
        pair<int, ll> pa = q.front(); q.pop();
        vis[pa.first] = 1;
        if(pa.first == t){
            cout << pa.second;
            return;
        }
        if(pa.first - 1 > 0 && !vis[pa.first - 1]) q.push({pa.first - 1, pa.second + 1});
        if(pa.first < t && !vis[pa.first  * 2]) q.push({pa.first * 2, pa.second + 1});
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
        memset(vis, 0, sizeof(vis));
        int s, t;
        cin >> s >> t;
        BFS(s, t);
        cout << '\n';
    }

    return 0;
}