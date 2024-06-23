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
        int dp[n + 1][k + 1];
        for(int i = 0; i <= n; i ++){
            for(int j = 0; j <= k; j ++){
                if(i == j || j == 0) dp[i][j] = 1;
                else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            }
        }
        cout << dp[n][k] << '\n';
    }

    return 0;
}