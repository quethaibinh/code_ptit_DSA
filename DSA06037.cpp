//code chua ac

#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n], ac[n], max_a[n] = {};
        vector<int> v;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            ac[i] = a[i];
        }
        sort(ac, ac + n);
        for(int i = 0; i < n; i ++){
            if(i == 0) max_a[i] = a[i];
            else max_a[i] = max(max_a[i - 1], a[i]);
        }
        for(int i = 0; i < n - 1; i ++){
            if(max_a[i] == ac[i]) v.push_back(i + 1);
        }
        cout << v.size() << '\n';
        for(int i = 0; i < v.size(); i ++) cout << v[i] << ' ';
        cout << '\n';
    } 

    return 0;
}