#include <iostream>
using namespace std;

int main ()
{
     int ini, end, digit;
     int res = 0;
     cin >> ini >> end >> digit;

     if(digit == 0 && ini == 0)
          res++;

     while(ini <= end){
          int temp = ini;
          while(temp > 0){
               if(temp % 10 == digit)
                    res++;
               temp = temp / 10;
          }
          ini++;
     }

     cout << res << endl;
}