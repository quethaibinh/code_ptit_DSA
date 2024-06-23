#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

bool check(string s, int i){
    return (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'));
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
        int n = s.size();
        ll dp[n + 1];
        bool kt = true;
        s = " " + s;
        dp[0] = 1;
        for(int i = 1; i <= n; i ++){
            if(s[i] == '0'){
                if(i == 1 || (s[i - 1] != '1' && s[i - 1] != '2')){
                    kt = false;
                    break;
                }
                dp[i] = dp[i - 2];
            }
            else{
                dp[i] = dp[i - 1];
                if(check(s, i)) dp[i] += dp[i - 2];
            }
        }
        if(kt) cout << dp[n] << '\n';
        else cout << 0 << '\n';
    }

}