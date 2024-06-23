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
        int n, x;
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; i ++) cin >> a[i];
        auto X = upper_bound(a, a + n, x);
        if(X - a == 0) cout << -1 << '\n';
        else cout << (X - a) << '\n';
    }  
    
    return 0;
}