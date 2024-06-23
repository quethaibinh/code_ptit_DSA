// code chua ac

#include<bits/stdc++.h>

using namespace std;
#define ll long long

int a1[10000006], a2[1000006], a3[1000006];

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
        bool check = false;
        set<ll> se1, se2, se3;
        map<ll, ll> mp;
        for(int i = 0; i < n; i ++){
            cin >> a1[i];
            se1.insert(a1[i]);
        }
        for(int i = 0; i < m; i ++){
            cin >> a2[i];
            se2.insert(a2[i]);
        }
        for(int i = 0; i < k; i ++){
            cin >> a3[i];
            se3.insert(a3[i]);
        }
        for(auto x : se1) mp[x] ++;
        for(auto x : se2) mp[x] ++;
        for(auto x : se3) mp[x] ++;
        for(auto x : mp){
            if(x.second == 3){
                check = true;
                cout << x.first << ' ';
            } 
        }
        if(!check) cout << -1;
        // for(auto x : se1) cout << x << ' ';
        // cout << '\n';
        // for(auto x : se2) cout << x << ' ';
        // cout << '\n';
        // for(auto x : se3) cout << x << ' ';
        // cout << '\n';
        cout << '\n';
    } 

    return 0;
}