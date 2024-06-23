#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n, k;
ll a[10005], b[10005];
void in(){
    for(ll i = 1; i <= k; i ++) cout << a[i] << ' ';
    cout << '\n';
}
void tryy(ll i, vector<ll> v){
    for(ll j = b[i - 1] + 1; j <= v.size() - k + i; j ++){
        b[i] = j;
        a[i] = v[j - 1];
        if(i == k) in();
        else tryy(i + 1, v);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif             

    cin >> n >> k;
    set<ll> se;
    vector<ll> v;
    for(ll i = 0; i < n; i ++){
        ll x; cin >> x;
        se.insert(x);
    }            
    for(auto x : se) v.push_back(x);
    tryy(1, v);
    
    return 0;
}