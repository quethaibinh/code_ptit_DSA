#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        string s; cin >> s;
        set<char> se1;
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); i ++) se1.insert(s[i]);
        int n = se1.size();
        int l = 0, r = 0;
        map<char, int> mp;
        set<char> se2;
        while(l <= r && r < s.size()){
            while(se2.size() != n){
                se2.insert(s[r]);
                mp[s[r ++]] ++;
            }
            while(se2.size() == n){
                mp[s[l]] --;
                if(mp[s[l]] == 0) se2.erase(s[l]);
                l ++;
            }
            ans = min(ans, r - l + 1);
        }
        cout << ans << '\n';
    }

    return 0;
}