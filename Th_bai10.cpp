#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll f[93], f2[93];
ll cnt;
ll tryy(ll n, ll k){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(k < f[n - 1]) return tryy(n - 1, k);
    if(k > f[n - 1]) return tryy(n - 2, k - f[n - 1]) + f[n - 1];
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t;
    cin >> t;
    f[1] = 1; f[2] = 1;
    for(int i = 2; i < 93; i ++){
        f[i] = f[i - 1] + f[i - 2];
    }
    while(t --){
        ll n, k;
        cin >> n >> k;
        cnt = 0;
        cout << tryy(n + 1, k) << '\n';
    }

    return 0;
}