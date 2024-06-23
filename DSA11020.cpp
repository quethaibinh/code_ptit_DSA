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
        int a[n];
        set<int> b;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            b.insert(a[i]);
        }
        bool check = true;
        if(b.size() < n) check = false;
        int i = 0;
        for(auto x : b)
            if(x != a[i ++]) check = false;
        if(check) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}