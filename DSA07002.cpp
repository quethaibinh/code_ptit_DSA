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
    vector<string> st;
    cin.ignore();
    while(t --){
        string s, token; getline(cin, s);
        // cout << s << '\n';
        vector<string> v;
        stringstream ss(s);
        while(ss >> token){
            v.push_back(token);
        }
        if(v[0] == "PUSH") st.push_back(v[1]);
        if(v[0] == "PRINT"){
            if(st.size() != 0) cout << st[st.size() - 1];
            else cout << "NONE";
            cout << '\n';
        }
        if(v[0] == "POP"){
            if(st.size() != 0) st.pop_back();
        }
    }

    return 0;
}