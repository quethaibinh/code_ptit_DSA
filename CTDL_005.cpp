#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif            

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }     
    int x;
    cin >> x;
    for(int i = 0; i < n; i ++){
        if(x == a[i]){
            continue;
        }
        cout << a[i] << ' ';
    }        
    // for(auto x : a) cout << x << ' ';
    
    return 0;
}