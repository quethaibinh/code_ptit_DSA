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
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        int ans = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == 1) dp[i][j] = 1;
                else if(i == 2 && s[j] == s[j + i - 1]){
                    dp[i][j] = 1;
                    ans = max(ans, i);
                }
                else{
                    if(s[j] == s[j + i - 1] && dp[i - 2][j + 1]){
                        dp[i][j] = 1;
                        ans = max(ans, i);
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}