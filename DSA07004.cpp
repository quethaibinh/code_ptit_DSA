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
        stack<char> st1, st2;
        int cnt = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(') st1.push(s[i]);
            else{
                if(!st1.empty() && st1.top() == '(') st1.pop();
                else st1.push(s[i]);
            }
        }
        while(!st1.empty()){
            if(st1.top() == ')'){
                if(st2.empty()){
                    st2.push(st1.top());
                }
                else{
                    cnt ++;
                    st2.pop();
                }
                st1.pop();
            }
            else{
                if(!st2.empty()) st2.pop();
                else{
                    st2.push(')');
                    cnt ++;
                }
                st1.pop();
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}