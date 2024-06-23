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
        int ans = 1;
        s = " " + s;
        int dp[105][105][105];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i ++){
            if(i == 1){
                for(int j = 1; j <= n; j ++){
                    for(int k = j + i - 1; k <= n; k ++) dp[i][j][k] = 1;
                }
            }
            else if(i == 2){
                for(int j = 1; j <= n; j ++){
                    for(int k = j + i - 1; k <= n; k ++){
                        if(s[j] == s[k]){
                            dp[i][j][k] = 1;
                            ans = max(ans, dp[i][j][k]);
                        }
                    }
                }
            }
            else{
                for(int j = 1; j <= n; j ++){
                    for(int k = j + i - 1; k <= n; k ++){
                        if(s[j] == s[k]){
                            for(int j1 = j + 1; j1 <= k - 1; j1 ++){
                                for(int k1 = j1 + i - 2; k1 <= k - 1; k1 ++){
                                    if(dp[i - 1][j1][k1]){
                                        dp[i][j][k] = 1;
                                        ans = max(ans, dp[i][j][k]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}