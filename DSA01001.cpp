#include<bits/stdc++.h>

using namespace std;

#define ll long long

void sinh(string s){
    int i = s.size() - 1;
    while(i >= 0 && s[i] == '1'){
        s[i] = '0';
        -- i;
    }
    if(i == -1){
        for(int j = 0; j < s.size(); j ++) cout << 0;
        cout << '\n';
    }
    else{
        s[i] = '1';
        cout << s << '\n';
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
        string s;
        cin >> s;
        sinh(s);
    }                      
    
    return 0;
}