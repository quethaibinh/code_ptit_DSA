#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool cmp(int a, int b){
    return a > b;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif      

    int n;
    cin >> n;
    int a[n];
    vector<int> left, right;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(i % 2 == 0) left.push_back(a[i]);
        else right.push_back(a[i]);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end(), cmp);
    for(int i = 0; i < n; i ++){
        if(i % 2 == 0) cout << left[i / 2] << ' ';
        else cout << right[i / 2] << ' ';
    }

    return 0;
}