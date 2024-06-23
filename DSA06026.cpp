#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif     

    ll n;
    cin >> n;
    ll a[n];
    for(auto &x : a) cin >> x;
    for(ll i = 0; i < n; i ++){
        bool check = false;
        for(ll j = 0; j < n - i; j ++){
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                check = true;
            }
        }
        if(check){
            cout << "Buoc " << i + 1 << ": ";
            for(ll j = 0; j < n; j ++) cout << a[j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}