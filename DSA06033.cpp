#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
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
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end(), cmp);
        int ans = -1, cnt = v[0].second;
        for(int i = 1; i < n; i ++){
            ans = max(ans, v[i].second - cnt);
            cnt = min(cnt, v[i].second);
        }
        cout << ans << '\n';
    }     

    return 0;
}