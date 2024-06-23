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
        map<int, int> mp;
        for(auto &x : a){
            cin >> x;
            mp[x] ++;
        }
        if(mp.find(x1) != mp.end()) cout << mp[x1] << '\n';
        else cout << -1 << '\n';
    }
    
    return 0;
}