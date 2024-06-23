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
        set<int> se;
        map<int, int> mp;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            se.insert(a[i]);
            if(mp.find(a[i]) == mp.end()) mp[a[i]] ++;
        }
        for(int i = 0; i < m; i ++){
            cin >> b[i];
            se.insert(b[i]);
            if(mp[b[i]] == 1) mp[b[i]] ++;
        }
        for(auto x : se) cout << x << ' ';
        cout << '\n';
        for(auto x : mp){
            if(x.second == 2) cout << x.first << ' ';
        }
        cout << '\n';
    }   
    
    return 0;
}