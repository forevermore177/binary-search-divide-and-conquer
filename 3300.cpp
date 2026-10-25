#include <iostream>
using namespace std;
using ll = long long;
string s;ll N;
int length;
void sfind(ll l,ll pos){ // 1-l
    if (l == length){
        cout<<s[pos-1];
        return;
    }
    if (pos <= l/2)
        sfind(l/2,pos);
    else{
        ll newpos;
        if (pos == l/2 + 1) newpos=l/2;
        else newpos=pos-l/2-1;
        sfind(l/2,newpos);
    }
}
int main(){
    cin>>s>>N;
    length = s.size();
    ll begin = length;
    while (begin<N){
        begin*=2;
    }
    sfind(begin, N);
}