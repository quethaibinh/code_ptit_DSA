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
        int n, x1;
        cin >> n >> x1;
        int a[n];
        for(auto &x : a) cin >> x;
        if(binary_search(a, a + n, x1)) cout << 1 << '\n';
        else cout << -1 << '\n';
    }     
    
    return 0;
}