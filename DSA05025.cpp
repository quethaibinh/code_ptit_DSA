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
        ll dp[n + 1];
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= n; i ++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
        cout << dp[n] << '\n';
    }

    return 0;
}