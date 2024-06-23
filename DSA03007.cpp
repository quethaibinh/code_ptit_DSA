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
        ll n; cin >> n;
        ll a[n], b[n];
        ll sum = 0;
        for(ll &i : a) cin >> i;
        for(ll &i : b) cin >> i;
        sort(a, a + n);
        sort(b, b + n);
        for(int i = 0; i < n; i ++){
            sum += (a[i] * b[n - i - 1]);
        }
        cout << sum << '\n';
    }

    return 0;
}