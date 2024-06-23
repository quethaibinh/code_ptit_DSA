#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve(int a[], int n){
    while(1){
        cout << '[';
        for(int i = 0; i < n; i ++){
            if(i != n - 1) cout << a[i] << ' ';
            else cout << a[i];
        } 
        cout << "]\n";
        if(n == 1) return;
        for(int i = 0; i < n - 1; i ++) a[i] += a[i + 1];
        n -= 1;
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n];
        for(auto &x : a) cin >> x;
        // for(auto x : a) cout << x << ' ';
        solve(a, n);
    }                        
    
    return 0;
}