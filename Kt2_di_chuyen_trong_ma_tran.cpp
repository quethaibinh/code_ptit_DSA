#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) dp[i][1] = dp[i - 1][1] + a[i][1];
    for(int i = 1; i <= m; i ++) dp[1][i] = dp[1][i - 1] + a[1][i];
    for(int i = 2; i <= n; i ++){
        for(int j = 2; j <= m; j ++) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    }
    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= m; j ++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << dp[n][m];

    return 0;
}