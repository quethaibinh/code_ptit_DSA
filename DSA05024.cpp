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
        int n, s; cin >> n >> s;
        int a[n + 1], dp[s + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= s; i ++){
            for(int j = 1; j <= n; j ++){
                if(a[j] <= i) dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
            }
        }
        cout << dp[s] << '\n';
    }

    return 0;
}