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
        ll sum = 0;
        for(int i = 0; i < s.size(); i ++){
            string s1 = "";
            for(int j = i; j < s.size(); j ++){
                s1 += s[j];
                sum += stoll(s1);
            }
        }
        cout << sum << '\n';
    }

    return 0;
}