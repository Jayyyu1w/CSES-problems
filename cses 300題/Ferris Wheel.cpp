/*船上最多只能載兩人 重量不能超過x 最少需要幾條船*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    deque<int> weight(n);
    for (int i = 0; i < n;i++){
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());
    int boats = 0;
    while(weight.size()>1){
        if(weight.front()+weight.back()<=x){
            weight.pop_front(), weight.pop_back();
            boats++;
        }else{
            weight.pop_back();
            boats++;
        }
    }
    if(weight.size()==1)
        boats++;
    cout << boats << "\n";
}