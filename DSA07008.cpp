#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int uuTien(char s){
    if(s == '+' || s == '-') return 1;
    if(s == '*' || s == '/') return 2;
    if(s == '^') return 3;
    return 0; // '('
}

void solve(string s){
    stack<char> st;
    string res = "";
    for(int i = 0; i < s.size(); i ++){
        if(isalpha(s[i])) res += s[i];
        else if(s[i] == '(') st.push(s[i]);
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop(); // pop '('
        }
        else{
            while(!st.empty() && uuTien(st.top()) >= uuTien(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty() && st.top() != '('){
        res += st.top();
        st.pop();
    }
    cout << res;
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
        solve(s);
        cout << '\n';
    }

    return 0;
}