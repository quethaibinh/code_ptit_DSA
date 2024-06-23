#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll fibo[93];
ll tryy(ll n, ll k){
    if(n == 1) return 1;
    if(k == fibo[n - 1]) return n;
    if(k < fibo[n - 1]) return tryy(n - 1, k);
    return tryy(n - 1, k - fibo[n - 1] - 1);
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
        fibo[0] = 0; fibo[1] = 1;
        for(int i = 2; i <= 92; i ++){
            fibo[i] = fibo[i - 1] * 2 + 1;
        }
        cout << tryy(n, k - 1) << '\n';
    } 
    
    return 0;
}