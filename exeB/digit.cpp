#include <iostream>
using namespace std;

int main ()
{
     int ini, end, digit;
     int res = 0;
     cin >> ini >> end >> digit;

     while(ini <= end){
          int temp = ini;
          while(temp > 1){
               if(temp % 10 == digit)
                    res++;

               temp = temp /10;
               if(temp == digit)
                    res++;
          }
          ini++;
     }
     cout << res << endl;
}