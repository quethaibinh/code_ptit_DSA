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

    int q; cin >> q;
    vector<int> v;
    while(q --){
        string s; cin >> s;
        if(s == "PUSH"){
            int t; cin >> t;
            v.push_back(t);
        }
        if(s == "PRINTFRONT"){
            cout << (!v.size() ? "NONE" : to_string(v[0]));
            cout << '\n';
        }
        if(s == "POP"){
            if(v.size()) v.erase(v.begin());
        }
    }

    return 0;
}