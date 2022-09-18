/*相鄰兩bitset只能差一個bit*/
#include<bits/stdc++.h>
using namespace std;

string tobinary(int n) {
    string s;
    while (n) {
        s += (n & 1 ? '1' : '0');
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    int n;
    cin >> n;
    vector<string> bin[n + 1];
    bin[1].push_back("0"), bin[1].push_back("1");
    for (int i = 2; i <= n;i++){
        int lim = pow(2, i);
        bin[i].assign(bin[i - 1].begin(), bin[i - 1].end());
        reverse(bin[i - 1].begin(), bin[i - 1].end());
        bin[i].insert(bin[i].end(), bin[i - 1].begin(), bin[i - 1].end());
        for (int j = 0; j < lim;j++){
            if (j < (lim >> 1)){
                bin[i][j] = "0" + bin[i][j];
            }else{
                bin[i][j] = "1" + bin[i][j];
            }
        }
    }
    int lim = pow(2, n);
    for (int i = 0; i < lim;i++){
        cout << bin[n][i] << "\n";
    }
}