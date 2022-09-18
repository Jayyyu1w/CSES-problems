/*問總共有幾種方法可以組合到目標值，骰子可以骰無限多次*/
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = i - 6; j < i;j++){
            if(j>=0){
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << "\n";
}