#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, k, a[1000006];
vector<vector<int>> v;
void tryy(int bd, vector<int> vc){
    for(int j = bd; j < n; j ++){
        vc.push_back(a[j]);
        if(vc.size() == k) v.push_back(vc);
        else tryy(j + 1, vc);
        vc.pop_back();
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
        cin >> n >> k;
        for(int i = 0; i < n; i ++) cin >> a[i];
        sort(a, a + n);
        tryy(0, {});
        // sort(v.begin(), v.end());
        for(auto x : v){
            for(int i = 0; i < x.size(); i ++) cout << x[i] << ' ';
            cout << '\n';
        }
        v.clear();
    }

    return 0;
}