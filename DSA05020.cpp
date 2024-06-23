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

    int t; cin >> t;
    while(t --){
        int n, m; cin >> n >> m;
        int a[n + 1][m + 1], dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++) cin >> a[i][j];
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(i == 1) dp[i][j] = dp[i][j - 1] + a[i][j];
                if(j == 1) dp[i][j] = dp[i - 1][j] + a[i][j];
                if(i != 1 && j != 1) dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + a[i][j];
        }
            }
        cout << dp[n][m] << '\n';
    }

    return 0;
}