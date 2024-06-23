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
        stack<char> st;
        int tmp = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(') st.push(s[i]);
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    tmp += 2;
                }
            }
        }
        cout << tmp << '\n';
    }

    return 0;
}