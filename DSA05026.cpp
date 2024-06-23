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

    int s, n; cin >> s >> n;
    int a[n + 1], dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= s; j ++){
            dp[i][j] = dp[i - 1][j];
            if(j > a[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
        }
    }
    cout << dp[n][s];

    return 0;
}