/*問n!的尾數最多有幾個0*/
//有一個2跟一個5才能在尾數增加一個0
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    ll ans = 0;
    cin >> n;
    while(n){
        ans += n /= 5;
    }
    cout << ans << "\n";
}