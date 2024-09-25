
// #include<sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int j = 0; 
    while(j < 2){
        fork();
        printf("_\n");
        j++;
    }
    cwait(NULL);
    return 0;
}