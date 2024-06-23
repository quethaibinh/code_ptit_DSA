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
        int a[n + 1], dpl[n + 1], dpr[n + 1];
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            dpl[i] = 1;
            dpr[i] = 1;
        }
        for(int i = 2; i <= n; i ++){
            if(a[i] > a[i - 1]) dpl[i] += dpl[i - 1];
        }
        for(int i = n - 1; i >= 1; i --){
            if(a[i] > a[i + 1]) dpr[i] += dpr[i + 1];
        }
        for(int i = 1; i <= n; i ++){
            ans = max(ans, dpl[i] + dpr[i] - 1);
        }
        cout << ans << '\n';
    }

    return 0;
}