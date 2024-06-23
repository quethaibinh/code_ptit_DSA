#include<bits/stdc++.h>

using namespace std;
#define ll long long

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
        string s;
        cin >> s;
        bool check = true;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i ++) mp[s[i]] ++;
        for(auto x : mp){
            if(x.second * 2 > s.size() + 1){
                check = false;
                break;
            }
        }
        // if(s.size() == 1) check = true;
        if(check) cout << 1 << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}