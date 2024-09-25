#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> d;
    d.insert(23);
    d.insert(13);
    for(auto i : d){
        cout << i << endl;
    }
}