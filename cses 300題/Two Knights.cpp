/*問n*n棋盤上兩騎士不會互相攻擊的擺放方法數*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> ways(n + 1, 0);
    ways[1] = 0;
    for (int i = 2; i <= n;i++){
        int power = i * i;
        if(i==2)
            ways[i] = power * (power - 1) / 2;
        else
            ways[i] = power * (power - 1) / 2 - (i - 2) * (6 + (i - 3) * 4) - 2 * (i - 2);
    }
    for (int i = 1; i <= n;i++){
        cout << ways[i] << "\n";
    }
}