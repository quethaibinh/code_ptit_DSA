#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll fibo[1000];
char tryy(ll n, ll k){
    if(n == 1) return 'A';
    if(k == fibo[n - 1]) return (n - 1 + 'A');
    if(k < fibo[n - 1]) return tryy(n - 1, k);
    else return tryy(n - 1, k - fibo[n - 1] - 1);
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
        fibo[1] = 1; fibo[2] = 3;
        for(int i = 2; i < 26; i ++) fibo[i] = fibo[i - 1] * 2 + 1;
        cout << tryy(n, k - 1) << '\n';
    }
    
    return 0;
}