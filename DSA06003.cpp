#include<bits/stdc++.h>

using namespace std;
#define ll long long

void testCase() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[k]) k = j;
        }
        if (k != i) {
            ans++;
            swap(a[i], a[k]);
        }
    }
    cout << ans;
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif       

    int t;
    cin >> t;
    while (t--) {
        testCase();
        cout << "\n";
    }
    return 0; 
    
    return 0;
}