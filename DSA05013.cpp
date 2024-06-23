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
        int n, k; cin >> n >> k;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= min(k, i); j ++){
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        cout << dp[n] << '\n';
    }

    return 0;
}