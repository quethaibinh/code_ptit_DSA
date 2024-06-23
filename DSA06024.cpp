#include<bits/stdc++.h>

using namespace std;
#define ll long long



int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif   

    int n, cnt = 1;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n - 1; i ++){
        int minPos = i;
        for(int j = i + 1; j < n; j ++){
            if(a[j] < a[minPos]) minPos = j;
        }
        swap(a[i], a[minPos]);
        cout << "Buoc " << cnt << ": ";
        for(int j = 0; j < n; j ++) cout << a[j] << ' ';
        cout << '\n';
        cnt ++;
    }     
    
    return 0;
}