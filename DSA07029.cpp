#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

void solve(string s){
    stack<string> st;
    string dig = "";
    string tex = "";
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '['){
            st.push(tex);
            tex = "";
            st.push(dig);
            dig = "";
            st.push(string(1, s[i]));
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            dig += s[i];
        }
        else if(s[i] == ']'){
            if(tex != "") st.push(tex); // chuoi cuoi cung (chuoi dau tien giai ma)
            tex = "";
            vector<string> v;

            // truong hop [[][][]]
            while(!st.empty() && st.top() != "["){
                v.push_back(st.top()); st.pop();
            }
            for(int j = v.size() - 1; j >= 0; j --) tex += v[j];
            st.pop(); // pop dau '['

            int siz = stoi(st.top()); st.pop(); // so lan lap
            string ans = "";
            for(int j = 0; j < siz; j ++) ans += tex;
            st.push(ans); // day them chuoi moi giai ma vao
            tex = "";
        }
        else tex += s[i];
    }
    // truong hop vi tri ngoai cung sau van con ki tu ([][]a)
    if(tex != "") st.push(tex);
    tex = "";

    // truong hop ben ngoai cung vi tri dau van con ki tu (abc3[[][]])
    vector<string> v;
    while(!st.empty()){
        v.push_back(st.top()); st.pop();
    }
    for(int i = v.size() - 1; i >= 0; i --) tex += v[i];
    st.push(tex);

    cout << st.top();
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
        solve(s);
        cout << '\n';
    }

    return 0;
}



//bai dung ne

// #include <bits/stdc++.h>
// using namespace std;

// void testCase() {
//     string s; cin >> s;
//     stack<string> st1;
//     stack<int> st2;
//     for (int i = 0; i < s.length(); ++i) {
//         if (s[i] >= '0' && s[i] <= '9') {
//             int num = 0;
//             while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
//                 num = num * 10 + (s[i] - '0');
//                 i++;
//             }
//             i--;
//             st2.push(num);
//         }
//         else if (s[i] == ']') {
//             string tmp = "";
//             while (st1.top() != "[") {
//                 tmp = st1.top() + tmp;
//                 st1.pop();
//             }
//             st1.pop(); // bo dau [

//             string res = "";
//             int dem = st2.top(); st2.pop();
//             while (dem--) res += tmp;
//             st1.push(res);
//         }
//         else {
//             st1.push(string(1, s[i]));
//             if (s[i] == '[' && (i == 0 || s[i - 1] < '0' || s[i - 1] > '9'))
//                 st2.push(1);
//         }
//     }

//     string ans = "";
//     while (!st1.empty()) {
//         ans = st1.top() + ans;
//         st1.pop();
//     }
//     cout << ans;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int T = 1; cin >> T;
//     while (T--) {
//         testCase();
//         cout << "\n";
//     }
//     return 0;
// }
