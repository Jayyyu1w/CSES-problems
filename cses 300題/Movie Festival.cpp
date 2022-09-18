/*給開始與結束時間，問最多能看幾場電影*/
#include<bits/stdc++.h>
using namespace std;

struct times{
    int st, ed;
    times(){}
    times(int _st,int _ed){
        st = _st, ed = _ed;
    }
    friend bool operator<(const times &a,const times&b){
        return a.ed < b.ed;
    }
};
int main(){
    int n, a, b;
    cin >> n;
    vector<times> t(n);
    for (int i = 0; i < n;i++){
        cin >> a >> b;
        t[i] = times(a, b);
    }
    sort(t.begin(), t.end());
    int e = t[0].ed, cnt = 1;
    for (int i = 1; i < n;i++){
        if(t[i].st>=e){
            e = t[i].ed;
            cnt++;
        }
    }
    cout << cnt << "\n";
}