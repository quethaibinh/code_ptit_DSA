#include<bits/stdc++.h>

using namespace std;
#define ll long long



int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif       

    int t;
    cin >> t;
    while(t --){
        int n, m;
        cin >> n >> m;
        ll a[n], b[m];
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        sort(a, a + n);
        sort(b, b + m);
        cout << a[n - 1] * b[0] << '\n'; 
    }
    
    return 0;
}