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
        int n; cin >> n;
        ll a[n + 1];
        ll chiphi = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            pq.push(a[i]);
        }
        while(pq.size() > 1){
            ll tmp1 = pq.top(); pq.pop();
            ll tmp2 = pq.top(); pq.pop();
            ll x = (tmp1 + tmp2) % MOD;
            chiphi = (chiphi + x) % MOD;
            pq.push(x);
        }
        cout << chiphi << '\n';
    }

    return 0;
}