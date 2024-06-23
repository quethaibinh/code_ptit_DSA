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

    string s;
    vector<string> st;
    while(getline(cin, s)){
        string token;
        vector<string> v;
        stringstream ss(s);
        while(ss >> token){
            v.push_back(token);
        }
        if(v[0] == "push") st.push_back(v[1]);
        if(v[0] == "show"){
            if(st.size() != 0){
                for(int i = 0; i < st.size(); i ++) cout << st[i] << ' ';
            }
            else cout << "empty";
            cout << '\n';
        }
        if(v[0] == "pop"){
            if(st.size() != 0) st.pop_back();
        }
    }

    return 0;
}