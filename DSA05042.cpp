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
        ll n, k; cin >> n >> k;
        ll a[n + 1];
        for(int i = 0; i < n; i ++) cin >> a[i];
        ll ans = a[0];
        bool check = false;
        int l = 0, r = 1;
        while(r <= n){
            if(ans < k) ans += a[r ++];
            else if(ans > k) ans -= a[l ++];
            else{
                if(l != r) check = true;
                break;
            }
        }
        // if(!check && ans > k && l < r){
        //     while(ans > k && l < r) ans -= a[l ++];
        //     if(ans == k) check = true;
        // }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}