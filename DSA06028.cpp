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
    vector<vector<int>> v;
    for(auto &x : a) cin >> x;
    for(int i = 0; i < n - 1; i ++){
        bool check = false;
        int min_pos = i;
        for(int j = i + 1; j < n; j ++){
            if(a[min_pos] > a[j]){
                min_pos = j;
                check = true;
            }
        }
        swap(a[i], a[min_pos]);
        // if(check) v.push_back(a);
        v.push_back(a);
    }
    for(int i = v.size() - 1; i >= 0; i --){
        cout << "Buoc " << i + 1 << ": ";
        for(auto x : v[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}