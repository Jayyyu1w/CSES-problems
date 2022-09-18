/*找總共有幾個不同數字*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, num;
    cin >> n;
    set<int> st;
    for(int i=0;i < n;i++){
        cin >> num;
        st.emplace(num);
    }
    cout << st.size() << "\n";
}