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
    
    int n;
    cin >> n;
    int a[n];
    for(auto &x : a) cin >> x;
    for(int i = 0; i < n; i ++){
        int pos = i;
        if(a[i] % 2 == 0){
            for(int j = i + 1; j < n; j ++){
                if(a[j] < a[pos] && a[j] % 2 == 0) pos = j;
            }
        }
        else{
            for(int j = i + 1; j < n; j ++){
                if(a[j] > a[pos] && a[j] % 2 != 0) pos = j;
            }
        }
        swap(a[i], a[pos]);
    }
    for(auto x : a) cout << x << ' ';

    return 0;
}