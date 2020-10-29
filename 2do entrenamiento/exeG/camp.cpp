#include <iostream>
#include <vector>

using namespace std;
vector<int> x,y;

int loop(int i, int j, int suma, vector<int> r){
     if(j != y.size()){
          int temp = abs(x[i] - y[j]);
          if(temp < suma){
               suma = temp;
               r[0] = i;
               r[1] = j;
          }
          suma = loop(i, j + 1, suma, r);
     }
     return suma;
}


int main(){
     int n, p, q, s, res = 0;


     cin >> n >> p >> q >> s;

     for(int i = 0; i < p; i++){
          int temp;
          cin >> temp; 
          x.push_back(temp);
     }

     for(int i = 0; i < q; i++){
          int temp;
          cin >> temp; 
          y.push_back(temp);
     }

     for(int i = 0; i < p; i++){
          vector<int> r = {0,0};
          int actual;

          actual = loop(i, 0, s + 1, r);

          x.erase(x.begin() + r[0]);
          y.erase(y.begin() + r[1]);

          if(i == 0){
               res = actual;
          }
          else if(actual > res){
               res = actual;
          }

          if(res > s){
               res = -1;
               break;
          }
     }

     cout << res << endl;

     return 0;
}