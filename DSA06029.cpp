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
    for(auto &x : a) cin >> x;
    vector<vector<int>> v;
    vector<int> vc;
    vc.push_back(a[0]);
    v.push_back(vc);
    for(int i = 1; i < a.size(); i ++){
        auto x = lower_bound(vc.begin(), vc.end(), a[i]);
        vc.insert(x, a[i]);
        v.push_back(vc);
    }
    for(int i = v.size() - 1; i >= 0; i --){
        cout << "Buoc " << i << ": ";
        for(auto x : v[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}