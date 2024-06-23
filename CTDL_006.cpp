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
    vector<int> v(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i];
    }
    for(int i = 0; i < n; i ++){
        int j = i + 1;
        while(j < v.size()){
            if(v[i] == v[j]){
                v.erase(j + v.begin());
                -- j;
            }
            j ++;
        }
    }
    for(auto x : v) cout << x << ' ';

    
    return 0;
}