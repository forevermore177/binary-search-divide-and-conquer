/*
sum{a1,...,ak}-max{a1,...ak} <=
sum{a1,...,ak+1}-max{a1,...ak+1}
*/
#include <iostream>
using namespace std;
int K,N,a[200001];
int presum[200001];

bool check_X(int X){
    int pos=0,finish=0,curmax=0,pre=-1;
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
    int maxa=1;
    for (int i=0;i<N;i++){
        cin>>a[i];
        if (a[i]>maxa) maxa=a[i];
        if (i==0) presum[0]=a[0];
        else presum[i]=presum[i-1]+a[i];
    }
    int l=0,r=presum[N-1]-maxa,ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
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