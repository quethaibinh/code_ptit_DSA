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
        int ans = 0;
        float a[n + 1], b[n + 1];
        int dp[n + 1];
        for(int i = 1; i <= n; i ++){
            cin >> a[i] >> b[i];
            dp[i] = 1;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j < i; j ++){
                if(a[i] > a[j] && b[i] < b[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}