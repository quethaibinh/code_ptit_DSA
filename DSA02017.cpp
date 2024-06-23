#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[100][100], used[1000], cheo1[1000], cheo2[1000];
int maxx;
int maxSum;
void tryy(int i){
    for(int j = 1; j <= 8; j ++){
        if(!used[j] && !cheo1[i + j - 1] && !cheo2[i - j + 8]){
            used[j] = 1;
            cheo1[i + j - 1] = 1;
            cheo2[i - j + 8] = 1;
            maxSum += a[i][j];
            if(i == 8){
                maxx = max(maxx, maxSum);
            }
            else tryy(i + 1);
            maxSum -= a[i][j];
            used[j] = 0;
            cheo1[i + j - 1] = 0;
            cheo2[i - j + 8] = 0;
        } 
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif        

    // int t;
    // cin >> t;
    // while(t --){
        maxx = 0;
        for(int i = 1; i <= 8; i ++){
            for(int j = 1; j <= 8; j ++) cin >> a[i][j];
        }
        tryy(1);
        cout << maxx << '\n';
    // }                 
    
    return 0;
}