#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll mod = 1000000007;

ll tryy(ll n, ll k){
    if(k == 0) return 1;
    if(k == 1) return n;
    ll X = tryy(n, k / 2);
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
        ll n, k;
        cin >> n >> k;
        cout << tryy(n, k) << '\n';
    }     
    
    return 0;
}