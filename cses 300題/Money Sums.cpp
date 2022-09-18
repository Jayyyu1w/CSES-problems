/*給n個不同價值硬幣，求所有價值組合*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, coin, sum = 0;
    cin >> n;
    bitset<100005> bs;
    bs[0] = 1;
    for (int i = 0; i < n;i++){
        cin >> coin;
        sum += coin;
        bs |= (bs << coin);
    }
    cout << bs.count() - 1 << "\n";
    for (int i = 1, cnt = 0; i <= sum;i++){
        if(bs[i]){
            if(cnt != 0)
                cout << " ";
            cout << i;
            cnt++;
        }
    }
    cout << "\n";
}