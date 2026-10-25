/*
assume we got an n*n,then how to get the 2a*2a?
the answer is: we create a new princess!
*/
#include <iostream>
using namespace std;

void bond(int st_x,int st_y,int x,int y,int length){
    if (length==2){
        if (x==st_x){
            if (y==st_y) {
                cout<<st_x+1<<" "<<st_y+1<<" 1\n";
                return;
            }
            else{
                cout<<st_x+1<<" "<<st_y<<" 2\n";
                return;
            }
        }
        else{
            if (y==st_y) {
                cout<<st_x<<" "<<st_y+1<<" 3\n";
                return;
            }
            else{
                cout<<st_x<<" "<<st_y<<" 4\n";
                return;
            }
        }
    }
    int mid_x = st_x+length/2;
    int mid_y = st_y+length/2;
    if (x<mid_x){
        if (y<mid_y){
            cout<<mid_x<<" "<<mid_y<<" 1\n";
            bond(st_x, st_y, x, y, length/2);
            bond(st_x, mid_y, mid_x-1, mid_y, length/2);//2
            bond(mid_x, st_y, mid_x, mid_y-1, length/2);//3
            bond(mid_x, mid_y, mid_x, mid_y, length/2);//4
        }
        else{
            cout<<mid_x<<" "<<mid_y-1<<" 2\n";
            bond(st_x, st_y, mid_x-1, mid_y-1, length/2);//1
            bond(st_x, mid_y, x, y, length/2);
            bond(mid_x, st_y, mid_x, mid_y-1, length/2);//3
            bond(mid_x, mid_y, mid_x, mid_y, length/2);//4
        }
    }
    else{
        if (y<mid_y){
            cout<<mid_x-1<<" "<<mid_y<<" 3\n";
            bond(st_x, st_y, mid_x-1, mid_y-1, length/2);//1
            bond(st_x, mid_y, mid_x-1, mid_y, length/2);//2
            bond(mid_x, st_y, x, y, length/2);
            bond(mid_x, mid_y, mid_x, mid_y, length/2);//4
        }
        else{
            cout<<mid_x-1<<" "<<mid_y-1<<" 4\n";
            bond(st_x, st_y, mid_x-1, mid_y-1, length/2);//1
            bond(st_x, mid_y, mid_x-1, mid_y, length/2);//2
            bond(mid_x, st_y, mid_x, mid_y-1, length/2);//3
            bond(mid_x, mid_y, x, y, length/2);
        }
    }
}
int main(){
    int k,x,y;
    cin>>k>>x>>y;
    int length=1;
    for (int i=0;i<k;i++)
        length*=2;
    bond(1, 1,  x,  y, length);
}