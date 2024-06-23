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
        vector<int> a(n);
        vector<vector<int>> v;
        for(auto &x : a) cin >> x;
        for(int i = 0; i < n; i ++){
            bool check = false;
            for(int j = 0; j < n - 1; j ++){
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                    check = true;
                }
            }
            if(check) v.push_back(a);
        }
        for(int i = v.size() - 1; i >= 0; i --){
            cout << "Buoc " << i + 1 << ": ";
            for(auto x : v[i]) cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}