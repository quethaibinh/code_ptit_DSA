// code loi chua sua duoc

#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, amax, maxtong;
int a[105][105];
int check[100005], a1[100007];
set<int> v;
void tryy(int i, int tong){
    for(int j = 1; j <= n; j ++){
        if(check[j] == 0){
            check[j] = 1; 
            if(tong + a[i][j] + (amax * (n - i)) > maxtong){
                if(i == n && tong + a[i][j] > maxtong) maxtong = tong + a[i][j];
                else tryy(i + 1, tong + a[i][j]);
            }
            check[j] = 0;
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    int t;
    cin >> t;
    while(t --){
        cin >> n;
        amax = 0;
        maxtong = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> a[i][j];
                amax = max(a[i][j], amax);
            }
        }
        tryy(1, 0);
        cout << maxtong << '\n';
    }                   
    
    return 0;
}