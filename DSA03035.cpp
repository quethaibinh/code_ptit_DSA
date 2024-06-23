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

    int n; cin >> n;
    int a[n + 1];
    int dp[n + 1], ans = 0;
    for(int i = 0; i <= n; i ++) dp[i] = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
        ans = max(ans, dp[a[i]]);
    }
    cout << n - ans << '\n';

    return 0;
}