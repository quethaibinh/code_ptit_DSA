#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        int n; cin >> n;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i ++){
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), cmp);
        int ans = 1;
        int cur = v[0].second;
        for(int i = 1; i < n; i ++){
            if(v[i].first >= cur){
                cur = v[i].second;
                ans ++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}