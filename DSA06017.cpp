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
        int a[n], b[m];
        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        sort(a, a + n);
        sort(b, b + m);
        int u = 0, d = 0;
        while(u < n && d < m){
            if(a[u] <= b[d]) cout << a[u ++] << ' ';
            else cout << b[d ++] << ' ';
        }
        if(u != n){
            for(int i = u; i < n; i ++) cout << a[i] << ' ';
        }
        if(d != m){
            for(int i = d; i < m; i ++) cout << b[i] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}