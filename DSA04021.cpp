#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll fibo[93];
char tryy(ll n, ll k){
    if(n == 1) return '0';
    if(n == 2) return '1';
    if(k <= fibo[n - 2]) return tryy(n - 2, k);
    else return tryy(n - 1, k - fibo[n - 2]);
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
        fibo[2] = fibo[1] = 1;
        for(int i = 3; i < 93; i ++) fibo[i] = fibo[i - 1] + fibo[i - 2];
        cout << tryy(n, k) << '\n';
    }
    
    return 0;
}