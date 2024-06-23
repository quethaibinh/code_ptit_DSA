#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n, sx, sy, ex, ey;
map<int, vector<pair<int, int>>> gx, gy;
map<int, int> mx, my;

void BFS(){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    map<pair<int, int>, int> mp;
    mp.insert({{sx, sy}, 1});
    for(auto it : gx[sx]){
        q.push(it);
        mp.insert({it, 1});
    }
    for(auto it : gy[sy]){
        q.push(it);
        mp.insert({it, 1});
    }
    mx[sx] = 1;
    my[sy] = 1;
    // for(auto it : mp){
    //     cout << it.first.first << ' ' << it.first.second << ' ' << it.second << '\n';
    // }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        // cout << x << ' ' << y << '\n';
        q.pop();
        if(mx[x] == 0){
            for(auto it : gx[x]){
                if(mp.find(it) == mp.end()){
                    mp.insert({it, mp[{x, y}] + 1});
                    q.push(it);
                }
            }
            mx[x] = 1;
        }
        if(my[y] == 0){
            for(auto it : gy[y]){
                if(mp.find(it) == mp.end()){
                    mp.insert({it, mp[{x, y}] + 1});
                    q.push(it);
                }
            }
            my[y] = 1;
        }
    }
    if(mp.find({ex, ey}) == mp.end()){
        cout << -1 << '\n';
    }
    else{
        cout << mp[{ex, ey}] - 1 << '\n';
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    cin >> n >> sx >> sy >> ex >> ey;
    for(int i = 1; i <= n; i ++){
        int u, v; cin >> u >> v;
        gx[u].push_back({u, v});
        gy[v].push_back({u, v});
    }
    gx[ex].push_back({ex, ey});
    gy[ey].push_back({ex, ey});
    BFS();

    return 0;
}