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
        set<int> se;
        map<int, int> mp;
        for(int i = 0; i < k; i ++){
            se.insert(a[i]);
            mp[a[i]] ++;
        }
        for(int i = 0; i < n - k + 1; i ++){
            cout << *se.rbegin() << ' ';
            se.insert(a[i + k]);
            mp[a[i + k]] ++;
            mp[a[i]] --;
            if(mp[a[i]] == 0) se.erase(a[i]);
        }
        cout << '\n';
    }

    return 0;
}