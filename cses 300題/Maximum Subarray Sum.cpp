/*最大子集合大小*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll cross(vector<ll>&arr,int l,int r,int mid){
    ll sum = 0, lsum=INT_MIN, rsum=INT_MIN;
    for (int i = mid; i >= l;i--){
        sum += arr[i];
        lsum = max(lsum, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= r;i++){
        sum += arr[i];
        rsum = max(rsum, sum);
    }
    return max({lsum, rsum, lsum + rsum});
}
ll dc(vector<ll>&arr, int l,int r){
    if(l==r)
        return arr[l];
    int mid = (l + r) >> 1;
    ll lsum = dc(arr, l, mid);
    ll rsum = dc(arr, mid + 1, r);
    return max({lsum, rsum, cross(arr, l, r, mid)});
}
int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    cout << dc(v, 0, n - 1) << "\n";
}