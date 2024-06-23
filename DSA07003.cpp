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
    cin.ignore();
    while(t --){
        string s; getline(cin, s);
        // cout << s << '\n';
        stack<char> st;
        bool check;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] != ')') st.push(s[i]);
            else{
                check = false;
                while(!st.empty()){
                    char tes = st.top(); st.pop();
                    if(tes == '+' || tes == '-' || tes == '*' || tes == '/') check = true;
                    if(tes == '(') break;
                }
                if(!check) break;
            }
        }
        cout << (!check ? "Yes\n": "No\n");
    }
}