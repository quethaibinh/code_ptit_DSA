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
        set<int> check;
        for(int i = 0; i < n; i ++){
            int x;
            cin >> x;
            check.insert(x);
        }
        if(check.size() >= 2) cout << *(check.begin()) << ' ' << *(++ check.begin()) << '\n';
        else cout << -1 << '\n';
    }      
    
    return 0;
}