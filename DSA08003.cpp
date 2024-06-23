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
        if(s == "PUSHBACK"){
            int t; cin >> t;
            v.push_back(t);
        }
        if(s == "PUSHFRONT"){
            int t; cin >> t;
            v.insert(v.begin(), t);
        }
        if(s == "POPBACK"){
            if(v.size()) v.pop_back();
        }
        if(s == "POPFRONT"){
            if(v.size()) v.erase(v.begin());
        }
        if(s == "PRINTBACK"){
            cout << (!v.size() ? "NONE" : to_string(v[v.size() - 1]));
            cout << '\n';
        }
        if(s == "PRINTFRONT"){
            cout << (!v.size() ? "NONE" : to_string(v[0]));
            cout << '\n';
        }
    }

    return 0;
}