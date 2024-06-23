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
    int a[n];
    for(auto &x : a) cin >> x;
    vector<int> v;
    v.push_back(a[0]);
    cout << "Buoc 0: " << a[0] << '\n';
    for(int i = 1; i < n; i ++){
        auto x = lower_bound(v.begin(), v.end(), a[i]);
        v.insert(x, a[i]);
        cout << "Buoc " << i << ": ";
        for(auto X : v) cout << X << ' ';
        cout << '\n';
    } 

    return 0;
}