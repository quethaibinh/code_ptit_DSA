#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

int n;
int a[1005];
vector<string> v;
void in(){
    string s = "";
    s += (a[1] + '0');
    for(int i = 2; i <= n; i ++){
        if(a[i - 1]) s += (abs(a[i] - 1) + '0');
        else s += (a[i] + '0');
    }
    v.push_back(s);
}

void tryy(int i ){
    for(int j = 0; j <= 1; j ++){
        a[i] = j;
        if(i == n) in();
        else tryy(i + 1);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);      

    int t; cin >> t;
    while(t --){
        string s; cin >> s;
        n = s.size();
        reverse(s.begin(), s.end());
        int ans = 0;
        for(int i = 0; i < s.size(); i ++){
            ans += (s[i] - '0') * pow(2, i);
        }
        tryy(1);
        cout << v[ans];
        v.clear();
        cout << '\n';
    }

    return 0;
}