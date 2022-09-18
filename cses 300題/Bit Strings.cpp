/*給字串長度，字串只包含0跟1，問有幾種字串組合*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll fastpow(ll n, ll base){
    ll ret = 1;
    while(n){
        if(n&1){
            ret = ret * base % MOD;
        }
        base = base * base % MOD;
        n >>= 1;
    }
    return ret;
}
int main(){
    ll n;
    cin >> n;
    ll ans = fastpow(n, 2);
    cout << ans << "\n";
}