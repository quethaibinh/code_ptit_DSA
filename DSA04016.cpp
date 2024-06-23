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
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m], c[m + n];
        for(int i = 0; i < n; i ++) cin >> a[i];
        for(int i = 0; i < m; i ++) cin >> b[i];
        int u = 0, d = 0, cnt = 0;
        while(u < n && d < m){
            if(a[u] < b[d]) c[cnt ++] = a[u ++];
            else c[cnt ++] = b[d ++];
        }
        if(u < n){
            for(int i = u; i < n; i ++) c[cnt ++] = a[i];
        }
        if(d < m){
            for(int i = d; i < m; i ++) c[cnt ++] = b[i];
        } 
        cout << c[k - 1] << '\n';
    }     
    
    return 0;
}