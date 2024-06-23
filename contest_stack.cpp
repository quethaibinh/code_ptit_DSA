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

    string s; cin >> s;
    stack<char> st1;
    stack<char> st2;
    for(auto x : s){
        if(x != '<' && x != '>' && x != '-') st1.push(x);
        if(x == '<' && !st1.empty()){
            st2.push(st1.top()); st1.pop();
        }
        if(x == '>' && !st2.empty()){
            st1.push(st2.top()); st2.pop();
        }
        if(x == '-' && !st1.empty()){
            st1.pop(); 
        }
    }
    string s2 = "";
    while(!st2.empty()){
        st1.push(st2.top()); st2.pop();
    }
    while(!st1.empty()){
        s2 += st1.top(); st1.pop();
    }
    reverse(s2.begin(), s2.end());
    cout << s2;

    return 0;
}