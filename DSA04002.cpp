#include<bits/stdc++.h>

using namespace std;
#define ll long long

int mod = 1000000007;
ll tryy(ll n, ll m){
    if(m == 0) return 1;
    if(m == 1) return n;
    ll X = tryy(n, m / 2) % mod;
    if(m % 2 == 0) return (X * X) % mod;
    return ((X * X) % mod * n) % mod;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    int t;
    cin >> t;
    while(t --){
        ll n;
        cin >> n;
        ll m = n, ld = 0;
        while(m >= 1){
            ld = ld * 10 + m % 10;
            m /= 10;
        }
        cout << tryy(n, ld) << '\n';
    }  
    
    return 0;
}