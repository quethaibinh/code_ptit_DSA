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

    int n; cin >> n;
    ll a[n + 1];
    map<ll, ll> mp;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    ll sum = 0;
    ll ans = 0;
    mp[sum] ++;
    for(int i = 1; i <= n; i ++){
        sum += a[i];
        if(mp.find(sum) != mp.end()) ans += mp[sum];
        mp[sum] ++;
    }
    cout << ans << '\n';
 
    return 0;
}