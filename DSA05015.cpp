#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
ll dp[1005][1005];

ll lyt(int n){
    ll lt = 1;
    for(int i = 2; i <= n; i ++) lt =(lt * i) % MOD;
    return lt;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    for(int i = 0; i <= 1000; i ++){
        for(int j = 0; j <= i; j ++){
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    int t; cin >> t;
    while(t --){
        int n, k; cin >> n >> k;
        cout << (dp[n][k] * lyt(k))% MOD << '\n';
    }

    return 0;
}