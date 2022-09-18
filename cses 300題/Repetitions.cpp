//最長連續字母串
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0, temp = 1;
    for (int i = 1; i < s.length();i++){
        if(s[i]!=s[i-1]){
            ans = max(ans, temp);
            temp = 1;
        }else{
            temp++;
        }
    }
    ans = max(ans, temp);
    cout << ans << "\n";
}