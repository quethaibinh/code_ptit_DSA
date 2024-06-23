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
        int cnt = 0;
        int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
        for(int i = 9; i >= 0; i --){
            while(n >= a[i]){
                n -= a[i];
                // cout << a[i] << ' ';
                cnt ++;
            }
            if(n == 0) break;
        }
        cout << cnt << '\n';
    }

    return 0;
}