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
        int a[n];
        for(auto &x : a) cin >> x;
        next_permutation(a, a + n);
        for(auto x : a) cout << x << ' ';
        cout << '\n';
    }                      
    
    return 0;
}