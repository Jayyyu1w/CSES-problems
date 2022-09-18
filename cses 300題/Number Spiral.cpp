//蛇行遞增矩陣，求(x,y)之值
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int y, x, tar;
        cin >> y >> x;
        tar = max(x, y);
        int rt = 1 + (2 + 2 * (tar - 1)) * (tar - 1) / 2;
        if(tar&1){
            if(tar==y){
                rt -= tar - x;
            }else{
                rt += tar - y;
            }
        }else{
            if(tar==y){
                rt += tar - x;
            }else{
                rt -= tar - y;
            }
        }
        cout << rt << "\n";
    }
}