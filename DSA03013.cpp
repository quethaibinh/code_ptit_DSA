#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

bool cmp(pair<char, int> a, pair<char, int> b){
    return a.second > b.second;
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
        int d; cin >> d;
        string s; cin >> s;
        int n = s.size();
        int check[n];
        vector<pair<int, int>> v;
        memset(check, 0, sizeof(check));
        map<char, int> mp;
        for(auto x : s) mp[x] ++;
        for(auto x : mp) v.push_back({x.first, x.second});
        sort(v.begin(), v.end(), cmp);
        int k = 0;
        bool check_t = true;
        for(int i = 0; i < v.size(); i ++){
            while(k < n){
                if(check[k]) k ++;
                else{
                    int j = k;
                    while(j < n && mp[v[i].first] > 0){
                        check[j] = 1;
                        j += d;
                        mp[v[i].first] --;
                    }
                    if(mp[v[i].first] > 0){
                        check_t = false;
                        break;
                    }
                }
                k ++;
            }
            if(!check_t) break;
        }
        if(check_t) cout << 1;
        else cout << -1;
        // for(int i = 0; i < n; i ++) cout << check[i] << ' ';
        cout << '\n';
    }

    return 0;
}