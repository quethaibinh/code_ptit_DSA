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

    queue<ll> q;
    vector<ll> v;
    q.push(1);
    while(!q.empty()){
        ll tes = q.front(); q.pop();
        if(tes >= 1e18) break;
        v.push_back(tes);
        q.push(tes * 10);
        q.push(tes * 10 + 1);
    }
    // for(auto i : v) cout << i << '\n';
    int t; cin >> t;
    while(t --){
        ll n; cin >> n;
        // ll v = pow(2, 63);
        // cout << v << '\n';
        auto x = lower_bound(v.begin(), v.end(), n);
        if(*x == n) cout << x - v.begin() + 1;
        else cout << x - v.begin();
        cout << '\n';
    }

    return 0;
}