#include<bits/stdc++.h>

using namespace std;
#define ll long long
typedef pair<int, int> ii;
const int MOD = 1e9 + 7;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        int n, m; cin >> n >> m;
        int a[n + 1][m + 1], dp[n + 1][m + 1];
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                cin >> a[i][j];
                dp[i][j] = 1e9;
            }
        }
        queue<ii> q;
        q.push({1, 1});
        dp[1][1] = a[1][1];
        while(!q.empty()){
            ii tmp = q.front(); q.pop();
            for(int i = 0; i < 4; i ++){
                int x1 = tmp.first + dx[i];
                int y1 = tmp.second + dy[i];
                if(x1 > 0 && x1 <= n && y1 > 0 && y1 <= m && dp[x1][y1] > dp[tmp.first][tmp.second] + a[x1][y1]){
                    dp[x1][y1] = dp[tmp.first][tmp.second] + a[x1][y1];
                    q.push({x1, y1});
                }
            }
        }
        // for(int i = 1; i <= n; i ++){
        //     for(int j = 1; j <= m; j ++) cout << dp[i][j] << ' ';
        //     cout << '\n';
        // }
        cout << dp[n][m] << '\n';
    }

    return 0;
}