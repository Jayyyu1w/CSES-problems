/*給一數字n，問能不能將1~n分兩組使得兩組分別的和相同，且印出兩陣列*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%4==1||n%4==2){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        vector<int> v1, v2;
        if(n%4==3){
            v1.push_back(1), v1.push_back(2);
            v2.push_back(3);
            for (int i = 4; i <= n;i++){
                if(i%4==0||i%4==3){
                    v1.push_back(i);
                }else{
                    v2.push_back(i);
                }
            }
        }else{
            for (int i = 1; i <= n;i++){
                if(i%4==0||i%4==1){
                    v1.push_back(i);
                }else{
                    v2.push_back(i);
                }
            }
        }
        cout << v1.size() << "\n";
        for (int i = 0; i < v1.size();i++){
            if(i!=0)
                cout << " ";
            cout << v1[i];
        }
        cout << "\n" << v2.size() << "\n";
        for (int i = 0; i < v2.size();i++){
            if(i!=0)
                cout << " ";
            cout << v2[i];
        }
        cout << "\n";
    }
}