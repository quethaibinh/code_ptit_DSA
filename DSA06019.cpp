#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second; 
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
        map<int, int> mp;
        vector<pair<int, int>> v;
        for(auto &x : a){
            cin >> x;
            mp[x] ++;
        }
        for(auto x : mp){
            v.push_back(x);
        }
        sort(v.begin(), v.end(), cmp);
        for(auto x : v){
            for(int j = 0; j < x.second; j ++){
                cout << x.first << ' ';
            }
        }
        cout << '\n';   
    }   
    
    return 0;
}