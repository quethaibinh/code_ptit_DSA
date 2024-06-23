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
        int a[n], sum_left[n], sum_right[n];
        bool check = false;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            if(i == 0) sum_left[i] = a[i];
            else sum_left[i] = sum_left[i - 1] + a[i];
        }
        for(int i = n - 1; i >= 0; i --){
            if(i == n - 1) sum_right[i] = a[i];
            else sum_right[i] = sum_right[i + 1] + a[i];
        }
        for(int i = 0; i < n; i ++){
            if(sum_left[i] == sum_right[i]){
                check = true;
                cout << i + 1;
                break;
            }
        }
        if(!check) cout << -1;
        cout << '\n';
    } 

    return 0;
}