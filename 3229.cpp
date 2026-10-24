#include <algorithm>
#include <iostream>
using namespace std;

int N,K,x[200001];
bool check(int D){
    int total=1,pre=0,pos=1;
    while (pos<N){
        while(pos<N && x[pos]-x[pre] < D) pos++;
        if (pos<N){
            total++;
            pre=pos;
            pos=pre+1;
        }
        else return false;
        if (total>=K) return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    for (int i=0;i<N;i++)
        cin>>x[i];
    sort(x,x+N);
    int l=1,r=x[N-1]-x[0],mid;
    while(l<r){
        mid=l+(r-l+1)/2;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l;
}