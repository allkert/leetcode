# include<iostream>

using namespace std;

int main(){
    char b[] = "ABCDEF";
    char *bp;
    for(bp = b; *bp; bp+=2){
        cout << *bp;
    }
}