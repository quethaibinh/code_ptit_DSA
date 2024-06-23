#include<bits/stdc++.h>

using namespace std;

#define ll long long

char x;
string s;
int used[1000006], ac[100005];
bool check(char x){
    return (x == 'A' || x == 'E');
}
void in(){
    for(int i = 0; i <= x - 'A'; i ++) cout << char(ac[i] + 'A');
    cout << '\n';
}
void tryy(int i){
    for(int j = 0; j <= (int)(x - 'A'); j ++){
        if(!used[j]){
            if(check(ac[i - 1] + 'A') && !check(j + 'A') && !check(ac[i - 2] + 'A'))  continue;
            used[j] = 1;
            ac[i] = j;
            if(i == (int)(x - 'A')) in();
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

    cin >> x; 
    for(int i = 0; i <= x - 'A'; i ++) s = s + (char)(i + 'A');  
    tryy(0);       
    // cout << s;         
    
    return 0;
}