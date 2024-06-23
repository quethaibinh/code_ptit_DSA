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
        int n, k;
        cin >> n >> k;
        int a[n];
        for(auto &x : a) cin >> x;
        sort(a, a + n);
        for(int i = n - 1; i >= n - k; i --){
            cout << a[i] << ' ';
        }
        cout << '\n';
    } 
    
    return 0;
}