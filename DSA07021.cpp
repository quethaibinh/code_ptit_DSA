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
        int ans = 0;
        stack<int> st; // luu vi tri cua dau ngoac
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(') st.push(i);
            else{
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                    if(!st.empty()) ans = max(ans, i - st.top()); // neu day dai nhat bat dau tu vi tri khac vi tri dau tien
                    else ans = max(ans, i + 1); // TH ma day dai nhat bat dau tu vi tri dau tien
                }
                else st.push(i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}