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
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '1'){
                if(s[i + 1] == '1') s[i + 1] = '0';
                else s[i + 1] = '1'; 
            }
        }   
        cout << s << '\n';
    }

    return 0;
}