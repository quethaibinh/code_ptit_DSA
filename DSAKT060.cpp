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
    s = " " + s;
    int q; cin >> q;
    while(q --){
        char check;
        int u, v;
        cin >> check >> u >> v;
        if(check == 'q'){
            string sc = s;
            reverse(sc.begin() + u, sc.begin() + v + 1);
            if(sc == s) cout << "YES\n";
            else cout << "NO\n";
        }
        if(check == 'c'){
            s.erase(s.begin() + u);
            s.insert(s.begin() + u, v + '0');
        }
    }

    return 0;
}
