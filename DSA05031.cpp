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
        int a[1000], dp[n + 1];
        for(int i = 1; i <= n; i ++) dp[i] = MOD;
        dp[0] = 0;
        int cnt = 0;
        for(int i = 1; i <= sqrt(n); i ++){
            a[i] = i * i;
            cnt ++;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= cnt; j ++){
                if(i >= a[j]) dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
        cout << dp[n] << '\n';
    }

    return 0;
}