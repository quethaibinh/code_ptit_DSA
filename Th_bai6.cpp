#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n;
int a[100005];
int used[100005];
string sc;
vector<vector<string>> v;
void in(vector<string> s){
    // for(int i = 1; i <= n; i ++) cout << a[i] << ' ';
    // cout << '\n';
    if(s[a[n] - 1] == sc){
        vector<string> x;
        for(int i = 1; i <= n; i ++) x.push_back(s[a[i] - 1]);
        v.push_back(x);
    }
}
void tryy(int i, vector<string> s){
    for(int j = 1; j <= n; j ++){
        if(!used[j]){
            used[j] = 1;
            a[i] = j;
            if(i == n) in(s);
            else tryy(i + 1, s);
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

    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i ++){
        cin >> s[i];
    }
    cin >> sc;
    // cout << s[3];
    tryy(1, s);
    sort(v.begin(), v.end());
    for(auto x : v){
        for(auto y : x) cout << y << ' ';
        cout << '\n';
    }

    return 0;
}