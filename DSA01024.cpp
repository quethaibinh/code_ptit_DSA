#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, k;
int a[100005];
vector<string> ten;
void in(){
    for(int i = 1; i <= k; i ++) cout << ten[a[i]] << ' ';
    cout << '\n';
}
void tryy(int i){
    for(int j = a[i - 1] + 1; j < ten.size() - k + i; j ++){
        a[i] = j;
        if(i == k) in();
        else tryy(i + 1);
    }
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("nhap.txt", "r", stdin);
    freopen("xuat.txt", "w", stdout);
    #endif  

    cin >> n >> k;
    string s, token;
    scanf("\n");
    getline(cin, s);        
    set<string> se;
    stringstream ss(s);
    while(ss >> token){
        se.insert(token);
    }               
    ten.push_back("-1");
    for(auto x : se) ten.push_back(x);
    // for(auto x : ten) cout << x << ' ';
    tryy(1);
    
    return 0;
} 