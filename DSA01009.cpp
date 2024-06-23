
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int n, k;
int a[100005];
vector<vector<char>> v;
void in(){
    bool check = true;
    for(int i = 1; i <= n; i ++){
        if(!check){
            int cnt = 0;
            int j = i;
            int check1 = true;
            while(j >= 0 && cnt < k){
                if(a[j] == 1) break;
                cnt ++;
                if(cnt == k) check1 = false;
                j --;
            }
            if(!check1) return;
        }
        else{
            int cnt = 0;
            int j = i;
            while(j >= 0 && cnt < k){
                if(a[j] == 0) cnt ++;
                else break;
                if(cnt == k){
                    check = false;
                }
                j --;
            }
        }
    }
    if(!check){
        vector<char> v1;
        for(int i = 1; i <= n; i ++){
            if(a[i] == 0) v1.push_back('A');
            else v1.push_back('B');
        }
        v.push_back(v1);
    }
}
void tryy(int i){
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

    a[0] = 1;
    cin >> n >> k;  
    tryy(1);  
    cout << v.size() << '\n';
    for(auto x : v){
        for(auto x1 : x) cout << x1;
        cout << '\n';
    }            
    
    return 0;
}