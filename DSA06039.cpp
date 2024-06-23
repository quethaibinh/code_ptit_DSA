#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n];
        bool check = false;
        map<int, int> mp;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            mp[a[i]] ++;
        }
        for(int i = 0; i < n; i ++){
            if(mp[a[i]] > 1){
                check = true;
                cout << a[i] << '\n';
                break;
            }
        }
        if(!check) cout << "NO\n";
    }  

    return 0;
}