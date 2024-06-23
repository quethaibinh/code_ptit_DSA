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
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n);
        ll cnt = 0;
        for(int i = 0; i < n - 1; i ++){
            auto x = lower_bound(a + i + 1, a + n, k - a[i]);
            auto y = upper_bound(a + i + 1, a + n, k - a[i]);
            cnt += y - x;
        }
        cout << cnt << '\n';
    } 

    return 0;
}