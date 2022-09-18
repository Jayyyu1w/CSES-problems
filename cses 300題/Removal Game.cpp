/*兩個玩家，每次可以取最左邊或最右邊，每位玩家都會取當前最優解，問第一位玩家所能取得的最大值是多少*/
/*區間dp*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>> dp;
vector<ll> v, pre;
ll dfs(int l,int r){
    if(dp[l][r]){
        return dp[l][r];
    }
    if(l==r){
        return dp[l][r] = v[l];
    }
    return dp[l][r] = max(v[l] + (pre[r] - pre[l]) - dfs(l + 1, r), v[r] + (pre[r - 1] - pre[l - 1]) - dfs(l, r - 1));
    //當前(左邊為l 右邊為r)的最大值，取當前最左或最右加上剩下的和(前綴和取和)減掉(l+1,r)或(l,r-1)位置的最大值
}
int main(){
    int n;
    cin >> n;
    dp.resize(n + 1, vector<ll>(n + 1, 0));     //dp一維是左邊的位置，一維是右邊的位置
    v.resize(n + 1);
    pre.resize(n + 1);
    for (int i = 1; i <= n;i++){
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }
    cout << dfs(1, n) << "\n";
}