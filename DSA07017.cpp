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
        int a[n], b[n];
        stack<int> st;
        for(int &i : a) cin >> i;

        // luu vao mang b nhung index(chi so) cua cac phan tu lon hon a[i] dau tien ben phai
        st.push(0);
        for(int i = 1; i < n; i ++){
            if(a[i] <= a[st.top()]) st.push(i);
            else{
                while(!st.empty() && a[i] > a[st.top()]){
                    b[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            b[st.top()] = -1;
            st.pop();
        }

        // cap nhat lai mang a luu cac gia tri nho hon a[i] dau tien ben phai
        st.push(0);
        for(int i = 1; i < n; i ++){
                if(a[i] >= a[st.top()]) st.push(i);
                else{
                    while(!st.empty() && a[i] < a[st.top()]){
                        a[st.top()] = a[i];
                        st.pop();
                    }
                    st.push(i);
                }
        }
        while(!st.empty()){
            a[st.top()] = -1;
            st.pop();
        }

        // in ra ket qua giong de bai a[b[i]]
        for(int i = 0; i < n;  i ++){
            if(b[i] != -1) cout << a[b[i]] << ' ';
            else cout << -1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}