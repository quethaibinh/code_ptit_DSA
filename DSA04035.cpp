#include<bits/stdc++.h>

using namespace std;
#define ll long long
int mod = 1e9 + 7;
ll n, k;

ll tryy(ll n, ll k){
    if(k == 0) return 1;
    ll X = tryy(n, k / 2);
    if(k % 2 == 0) return (X * X) % mod;
    return ((X * X) % mod * n) % mod;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif       

    while(cin >> n >> k){
        if(n == 0 && k == 0) break;
        cout << tryy(n, k) << '\n';
    } 
    
    return 0;
}