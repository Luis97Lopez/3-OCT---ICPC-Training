#include <iostream>
#include <vector>

using namespace std;

int n;

vector<string> out;


void printMayorLinea(int renglon, vector<vector<int>> array){
     int mayor = 0;
     int res = -1;
     int count = 0;
     for(int i=0; i < n; i++){
          if(i != renglon){
               if(array[renglon][i] > mayor){
                    mayor = array[renglon][i];
                    count = 1;
                    res = i;
               }else if(array[renglon][i] == mayor){
                    count++;
               }
          }
     }

     if(mayor == 0){
          out.push_back("No info");
     }else if(count > 1){
          out.push_back("Multiple");
     }else{
          out.push_back(to_string(res));
     }
}


void printMayorMatriz(vector<vector<int>> array){
     int mayor = -1;
     int resi = -1;
     int resj = -1;
     int count = 0;
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++){
               if(i != j){
                    if(array[i][j] > mayor){
                         mayor = array[i][j];
                         count = 1;
                         resi = i;
                         resj = j;
                    }else if(array[i][j] == mayor){
                         count++;
                    }
               }  
          }
     }

     if(count > 1){
          out.push_back("Multiple");
     }else{
          out.push_back(to_string(resi) + " " + to_string(resj));
     }
}


int main(){
     int lines;

     cin >> n >> lines;
     vector<vector<int>> pairs(n, vector<int> (n, 0));

     for(int idx = 0; idx < lines; idx++){
          char c;
          int i, j;
          cin >> c;
          switch(c){
               case 'R':
                    cin >> i >> j;
                    pairs[i][j]++;
                    break;
               case 'Q':
                    cin >> i;
                    printMayorLinea(i, pairs);
                    break;
               case 'B':
                    printMayorMatriz(pairs);
                    break;
          }
     }

     for(auto o : out){
          cout << o << "\n";
     }
}