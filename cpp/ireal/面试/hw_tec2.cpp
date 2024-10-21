#include<iostream>
#include<cmath>


using namespace std;

unsigned int ShartestRath(unsigned int ax, unsigned int ay, unsigned int bx, unsigned int by, unsigned int fx, unsigned int fy){
    if(fx >= min(ax, bx) && fx <= max(ax, bx) && fy >= min(ay, by) && fy <= max(ay, by)){
        if(ax == bx && ax == fx) return abs(ay - by) + 2;
        else if(ay == by && ay == fy) return abs(ax - bx) + 2;
        else return abs(ax-bx) + abs(ay - by);
    }
    else return abs(ax-bx) + abs(ay - by);
}

int main(){
    int ax = 
}