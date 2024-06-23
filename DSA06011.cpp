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
        for(auto &x : a) cin >> x;
        // sort(a, a + n);
        int minn = INT_MAX;
        int kq;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                if(minn > abs(a[i] + a[j])){
                    minn = abs(a[i] + a[j]);
                    kq = a[i] + a[j];
                }
            }
        }
        cout << kq << '\n';
    }   
    
    return 0;
}