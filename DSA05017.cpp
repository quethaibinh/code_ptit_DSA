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
        int a[n + 1], dpx[n + 1], dpn[n + 1];
        int ans = 0;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i ++){
            dpx[i] = a[i];
            for(int j = 1; j < i; j ++){
                if(a[i] > a[j]) dpx[i] = max(dpx[i], dpx[j] + a[i]);
            }
        }
        for(int i = n; i >= 1; i --){
            dpn[i] = a[i];
            for(int j = n; j > i; j --){
                if(a[i] > a[j]) dpn[i] = max(dpn[i], dpn[j] + a[i]);
            }
        }
        for(int i = 1; i <= n; i ++){
            ans = max(ans, dpx[i] + dpn[i] - a[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}