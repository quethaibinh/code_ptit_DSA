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
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int l = 0, r = n - 1;
        while(l < r){
            if(a[l] == b[l]) l ++;
            if(a[r] == b[r]) r --;
            if(a[l] != b[l] && a[r] != b[r]) break;
        }
        cout << l + 1 << ' ' << r + 1 << '\n';
    }

    return 0;
}