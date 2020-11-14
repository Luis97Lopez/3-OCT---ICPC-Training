#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


int main(){
    cout << 100000 << endl;
    srand(time(NULL));
    for(int i = 0; i < 100000; i++){
        cout << (int)rand() << " " << (int)rand() << endl;
    }
}