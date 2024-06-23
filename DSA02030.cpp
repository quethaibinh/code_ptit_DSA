#include<bits/stdc++.h>

using namespace std;

#define ll long long

char x;
int k, a1[100005];
char a[100005];
void in(){
    for(int i = 1; i <= k; i ++) cout << a[a1[i]];
    cout << '\n';
}
void tryy(int i){
    for(int j = a1[i - 1]; j <= (int)(x - 'A'); j ++){
        a1[i] = j;
        if(i == k) in();
        else tryy(i + 1);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif   

    cin >> x >> k;
    for(int i = 0; i <= int(x - 'A'); i ++){
        a[i] = char(i + 'A');
    }
    tryy(1);
    // for(int i = 0; i <= int(x - 'A'); i ++) cout << a[i];
    
    return 0;
}