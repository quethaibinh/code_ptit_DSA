#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      
    
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int bd[n], kt[n];
        vector<pair<int, int>> v;
        for(auto &x : bd) cin >> x;
        for(int i = 0; i < n; i ++){
            cin >> kt[i];
            v.push_back({bd[i], kt[i]});
        }
        sort(v.begin(), v.end(), cmp);
        int cur_cnt = 1;
        int cur = v[0].second;
        for(int i = 1; i < n; i ++){
            if(v[i].first >= cur){
                cur = v[i].second;
                cur_cnt ++;
            }
        }
        cout << cur_cnt << '\n';
    }

    return 0;
}