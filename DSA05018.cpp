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
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        int ans = 0;
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n - i + 1; j ++){
                if(s[j] == s[j + i - 1]){
                    if(i == 1) dp[j][j] = 1;
                    if(i == 2) dp[j][j + i - 1] = 2;
                    if(i > 2 && dp[j + 1][j + i - 2] != 0) dp[j][j + i - 1] = dp[j + 1][j + i - 2] + 2;
                    ans = max(ans, dp[j][j + i - 1]);
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}