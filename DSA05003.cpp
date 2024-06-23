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
        int n, m, k; 
        cin >> n >> m >> k;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        s1 = " " + s1; s2 = " " + s2; s3 = " " + s3;
        int dp[n + 1][m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                for(int x = 1; x <= k; x ++){
                    if(s1[i] == s2[j] && s2[j] == s3[x]) dp[i][j][x] = dp[i - 1][j - 1][x - 1] + 1;
                    else dp[i][j][x] = max(dp[i - 1][j][x], max(dp[i][j - 1][x], dp[i][j][x - 1]));
                }
            }
        }
        cout << dp[n][m][k] << '\n';
    }

    return 0;
}