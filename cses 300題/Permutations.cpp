//1~n排列，相鄰兩數差距不能為1
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << "1\n";
    }else if(n<=3){
        cout << "NO SOLUTION\n";
    }
    else{
        for (int i = 2; i <= n;i+=2){
            if(i!=2)
                cout << " ";
            cout << i;
        }
        cout << " ";
        for (int i = 1; i <= n;i+=2){
            if(i!=1)
                cout << " ";
            cout << i;
        }
        cout << "\n";
    }
}