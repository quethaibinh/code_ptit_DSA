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
        int n; cin >> n;
        ll a[n + 1], dp[n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i ++) cin >> a[i];
        dp[1] = a[1];
        for(int i = 2; i <= n; i ++) dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        cout << dp[n] << '\n';
    }

    return 0;
}