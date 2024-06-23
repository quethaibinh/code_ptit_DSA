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

    int t;
    cin >> t;
    while(t --){
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        s1 = " " + s1;
        s2 = " " + s2;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        cout << dp[n][m] << '\n';
    }

    return 0;
}