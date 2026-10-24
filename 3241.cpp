/*
sum{a1,...,ak}-max{a1,...ak} <=
sum{a1,...,ak+1}-max{a1,...ak+1}
*/
#include <iostream>
using namespace std;
using ll =long long;
ll K,N,a[200001];
ll presum[200001];
// int * 1e5 >> ll 
bool check_X(ll X){
    ll pos=0,finish=0,curmax=0,pre=-1;
    while (pos<N){
        if (a[pos]>curmax) curmax =a[pos];
        if (presum[pos]-curmax > X){
            curmax=a[pos];
            finish++;
            pre=pos;
            pos++;
            break;
        }
        pos++;
    }
    while (pos<N){
        if (a[pos]>curmax) curmax =a[pos];
        if (presum[pos]-presum[pre-1]-curmax>X){
            curmax=a[pos];
            finish++;
            if (finish > K) return false;
            pre=pos;
        }
        pos++;
    }
    if (finish+1>K)return false;
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    ll maxa=1;
    for (ll i=0;i<N;i++){
        cin>>a[i];
        if (a[i]>maxa) maxa=a[i];
        if (i==0) presum[0]=a[0];
        else presum[i]=presum[i-1]+a[i];
    }
    ll l=0;
    ll r=presum[N-1]-maxa,ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if (check_X(mid)){
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    cout<<ans;
}