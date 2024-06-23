#include<bits/stdc++.h>

using namespace std;
#define ll long long

string s;
ll a[501], ok;
vector<ll> v;
void sinh(){
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '9'){
        s[i] = '0';
        i --;
    }
    if(i == -1) ok = 0;
    else s[i] = '9';
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      
     
    int t;
    cin >> t;
    s = "0000000000000";
    ok = 1;
    sinh();
    int cnt = 0;
    while(ok){
        ll x = stoll(s);
        for(int i = 1; i <= 500; i ++){
            if(a[i] == 0 && x % i == 0){
                // cnt ++;
                a[i] = x;
            }
        }
        sinh();
    }
    // cout << cnt << '\n';
    while(t --){
        int n;
        cin >> n;
        cout << a[n] << '\n';
    }

    return 0;
}