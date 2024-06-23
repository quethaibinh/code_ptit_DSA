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
        int n, s; cin >> n >> s;
        int a[n + 1], dp[s + 1];
        for(int i = 1; i <= n; i ++) cin >> a[i];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = s; j >= a[i]; j --){
                if(dp[j - a[i]]) dp[j] = 1;
            }
        }
        if(dp[s]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}