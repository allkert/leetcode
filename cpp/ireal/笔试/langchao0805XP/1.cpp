# include<iostream>
using namespace std; 

class P{
private:
    int ival;
public:
    P();
    ~P();
    int GetVal(){
        return ival;
    }
    virtual int setVal(int val){
        ival = val;
        return val;
    }
};
int main(){
    int a = -1, b = 4, k;
    k = (++a < 0)&&(b-- <= 0);
    cout << a << b << k;
}

