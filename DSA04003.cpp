#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll mod = 123456789;
ll tryy(ll n, ll k){
    if(k == 1) return n;
    ll X = tryy(n, k / 2) % mod;
    if(k % 2 == 0) return (X * X) % mod;
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
        cout << tryy(2, n - 1) << '\n';
    }      
    
    return 0;
}