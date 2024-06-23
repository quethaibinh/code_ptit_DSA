#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void sovle(string s){
    stack<string> st;
    for(int i = 0; i < s.size(); i ++){
        if(isalpha(s[i])) st.push(string(1, s[i]));
        else{
            string d1 = st.top(); st.pop();
            string d2 = st.top(); st.pop();
            st.push(d2 + s[i] + d1);
        }
    }
    cout << st.top();
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
        string s; cin >> s;
        sovle(s);
        cout << '\n';
    }

    return 0;
}