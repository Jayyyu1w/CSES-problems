/*問最小不能組合的硬幣價值*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll sum = 1;
    for (int i = 0; i < n;i++){
        if(v[i]<=sum)   //下一個還未超過目前總和+1，代表有機會用他創造出總和+1
            sum += v[i];
        else            //下一個超過目前總和+1，代表已無法創造出總和+1
            break;
    }
    cout << sum << "\n";
}