#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif        

    int t;
    cin >> t;
    while(t --){
        int n, k;
        cin >> n >> k;
        int a[n];
        ll ans = 0;
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        for(int i = 0; i < n; i ++){
            auto r = lower_bound(a, a + n, k + a[i]);
            ans += (r - a - i - 1);
        }
        cout << ans << '\n';
    }

    return 0;
}