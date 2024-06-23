#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int vis[10][10];
void check(string &s){
    s = to_string((s[0] - 'a' + 1)) + s[1];
    return;
}

void BFS(string s1, string s2){
    int i1 = (s1[0] - '0'), i2 = (s2[0] - '0');
    int j1 = (s1[1] - '0'), j2 = (s2[1] - '0');
    cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << '\n';
    queue<pair<pair<int, int>, ll>> q;
    q.push({{i1, j1}, 0});
    vis[i1][j1] = 1;
    while(!q.empty()){
        pair<pair<int, int>, ll> pa = q.front(); q.pop();
        if(pa.first.first == i2 && pa.first.second == j2){
            cout << pa.second;  
            return;
        }
        for(int i = 0; i < 8; i ++){
            int ix = pa.first.first + dx[i];
            int jx = pa.first.second + dy[i];
            cout << ix << ' ' << jx << '\n';
            if(ix <= 8 && ix >= 1 && jx <= 8 && jx >= 1 && !vis[ix][jx]){
                vis[ix][jx] = 1;
                q.push({{ix, jx}, pa.second + 1});
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
        memset(vis, 0, sizeof(vis));
        string s1, s2; cin >> s1 >> s2;
        // cout << check(s1) << ' ' << check(s2) << '\n';
        check(s1);
        check(s2);
        BFS(s1, s2);
        cout << '\n';
    }

    return 0;
}