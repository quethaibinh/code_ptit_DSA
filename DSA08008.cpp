#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
vector<string> a(100005, "0");

bool check(string s, int x){
    int xche = 0;
    for(int i = 0; i < s.size(); i ++){
        xche = ((xche * 10) % x + (s[i] - '0') % x) % x;
    }
    if(xche == 0) return true;
    return false;
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
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        ll cnt = 0;
        while(!q.empty()){
            string tes = q.front(); q.pop();
            if(check(tes, n)){
                cout << tes;
                break;
            }
            q.push(tes + "0");
            q.push(tes + "1");
        }
        cout << '\n';
    }

    return 0;
}