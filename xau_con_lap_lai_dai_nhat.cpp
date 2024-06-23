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
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        s = " " + s;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i != j && s[i] == s[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        cout << dp[n][n] << '\n';
    }

    return 0;
}