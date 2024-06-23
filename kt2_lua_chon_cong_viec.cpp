#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i ++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    ll res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i ++){
        pq.push(v[i].second);
        while(v[i].first < pq.size()) pq.pop();
    }
    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
    cout << res;

    return 0;
}