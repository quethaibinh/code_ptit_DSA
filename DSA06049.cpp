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
        ll n, k, cnt = 0;
        cin >> n >> k;
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        for(ll i = 0; i < n; i ++){
            auto x = lower_bound(a + i + 1, a + n, k + a[i]);
            cnt += (x - a - i - 1);
        }
        cout << cnt << '\n';
    }   

    return 0;
}