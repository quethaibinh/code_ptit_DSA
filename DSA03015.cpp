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
        int n, s, m;
        cin >> n >> s >> m;
        float max_tt = s * m;
        float max_mua = n * (s - (s / 7));
        if(max_mua < max_tt) cout << -1;
        else{
            cout << ceil(max_tt / n);
        }
        cout << '\n';
    }

    return 0;
}