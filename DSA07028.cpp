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
        int n; cin >> n;
        int ckhoan[n], nhip[n];
        stack<int> st;
        for(int i = 0; i < n; i ++){
            cin >> ckhoan[i];
            nhip[i] = 1;
        }
        st.push(0);
        for(int i = 1; i < n; i ++){
            if(ckhoan[i] < ckhoan[st.top()]) st.push(i);
            else{
                while(!st.empty() && ckhoan[i] >= ckhoan[st.top()]){
                    nhip[i] += nhip[st.top()];
                    st.pop();
                }
                st.push(i);
            }
        }
        for(int i : nhip) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}