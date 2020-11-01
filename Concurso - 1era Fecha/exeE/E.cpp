#include  <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool answer = false;
int N;
int res = -1;
string s;
unsigned t0, t1;

bool isPrime(int x){
    if (x == 0 || x == 1) {
        return false;
    }
    else {
        for (int i = 2; i <= x / 2; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}


void generate(string n1, string n2, string n3){

     if(n1[0] == '0' || n2[0] == '0' || n3[0] == '0')
          return;

     if( n1.size() + n2.size() + n3.size() == N){
          int t1, t2, t3;
          t1 = stoi(n1);
          t2 = stoi(n2);
          t3 = stoi(n3);
          if(isPrime(t1) && isPrime(t2) && isPrime(t3)){
               
               int temp = t1 * t2 * t3;
               if(!answer){
                    answer = true;
                    res = temp;
               }else if(temp < res){
                    res = temp;
               }
          }
     }
}



int main(){

     cin >> s;

     N = s.size();

     int my_ints[N];
     for(int i = 0; i < N; i++){
          my_ints[i]  = i;
     }

     // Se generan las permutaciones
     do {
          string new_s = "";
          
          for(int i = 0; i < N; i ++){
               new_s += s[my_ints[i]];
          }
          // Se generan las combinaciones
          for(int i = 1; i < N; i++){
               for(int j = 1; j < N - i ; j++){
                    generate (
                         new_s.substr(0, i),
                         new_s.substr(i, j),
                         new_s.substr(i+j)
                    );  
               }
          }
     } while (next_permutation(my_ints, my_ints + N));

     if(!answer){
          cout << "Bob lies" << endl;
     }else{
          cout << res << endl;
     }
     
     
     return 0;
}
