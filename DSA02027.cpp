// code nguoi du lich

#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, a[106][106], used[100005], ac[1000006];
int cmin = INT_MAX, kq = INT_MAX;
void nhap(){
    cin >> n;
    ac[1] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
            if(i != j) cmin = min(cmin, a[i][j]);
        }
    }
}
void tryy(int i, int qd){
    for(int j = 2; j <= n; j ++){
        if(!used[j]){
            used[j] = 1;
            ac[i] = j;
            if(qd + a[ac[i - 1]][ac[i]] + (n - i + 1) * cmin <= kq){
                if(i == n) kq = min(kq, qd + a[ac[i - 1]][ac[i]] + a[ac[n]][ac[1]]);
                else tryy(i + 1, qd + a[ac[i - 1]][ac[i]]);
            } 
            used[j] = 0;
        }
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      
    
    nhap();
    tryy(2, 0);
    cout << kq;

    return 0;
}