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
        set<int> se;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            int x = a[i];
            while(x >= 1){
                se.insert(x % 10);
                x /= 10;
            }
        }
        for(auto x : se) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}