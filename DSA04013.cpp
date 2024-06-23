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
        int n;
        cin >> n;
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        int l = n / 2 - 1, r = n - 1, ans = n;
        while(l >= 0 && r >= n / 2){
            if(a[r] >= a[l] * 2){
                ans --;
                r --; l --;
            }
            else l --;
        }
        cout << ans << '\n';
    }

    return 0;
}