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
        int n, m; cin >> n >> m;
        int a[n + 1][m + 1];
        int dp[n + 1][m + 1];
        int ans = 0;
        int answ, ansh;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                cin >> a[i][j];
                if(i == 1) dp[i][j] = a[i][j];
                else dp[i][j] = 0;
            }
        }
        for(int i = 2; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                // dp luu cac chieu cao cua cac hinh chu nhat
                if(a[i][j]) dp[i][j] = dp[i - 1][j] + 1;
            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                int height = dp[i][j];
                for(int k = j; k <= m; k ++){
                    // tinh chieu cao cua hinh chu nhat
                    height =  min(height, dp[i][k]);
                    // tinh chieu rong cua hinh chu nhat
                    int width = k - j + 1;
                    if(width * height > ans){
                        ans = width * height;
                        answ = width;
                        ansh = height;
                    }
                    if(width * height == ans){
                        int x = min(width, height);
                        int y = max(width, height);
                        if(y - x < abs(answ - ansh)){
                            answ = x;
                            ansh = y;
                        }
                    }
                }
            }
        }
        cout << answ << ' ' << ansh << '\n';
        // cout << ans << '\n';
    }

    return 0;
}