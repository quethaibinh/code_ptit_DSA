#include<bits/stdc++.h>

using namespace std;

#define ll long long

string s;
int a[100005], used[100005];
void in(){
    for(int i = 0; i < s.size(); i ++) cout << s[a[i]];
    cout << ' ';
}
void tryy(int i){
    for(int j = 0; j < s.size(); j ++){
        if(!used[j]){
            used[j] = 1;
            a[i] = j;
            if(i == s.size() - 1) in();
            else tryy(i + 1);
            used[j] = 0;
        }
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
        cin >> s;
        tryy(0);
        cout << '\n';
    }                       
    
    return 0;
}