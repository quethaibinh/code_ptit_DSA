#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;
        int a[n], ac[n];
        bool check = true;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            ac[i] = a[i];
        }
        sort(ac, ac + n);
        for(int i = 0; i < n; i ++){
            if(a[i] != ac[i] && a[i] != ac[n - i - 1]){
                check = false;
                break;
            }
        }
        if(check) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}