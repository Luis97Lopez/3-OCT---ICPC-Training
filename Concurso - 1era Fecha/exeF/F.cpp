#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> holes = {         make_pair("hole in one", 0), 
                                   make_pair("condor", -4),
                                   make_pair("albatross", -3),
                                   make_pair("eagle", -2),
                                   make_pair("birdie", -1),
                                   make_pair("par", 0),
                                   make_pair("bogey", 1),
                                   make_pair("double bogey", 2),
                                   make_pair("triple bogey", 3)
                                   };

int main(){
     vector<int> numbers;
     int i_temp, res = 0;
     string s_temp;

     for(int i=0; i < 18; i ++){
          cin >> i_temp;
          numbers.push_back(i_temp);
     }

     cin.ignore(0, '\n');

     for(int i = 0; i < 18; i++){
          getline(cin, s_temp);
          cin.ignore(0, '\n');

          if(s_temp == "hole in one"){
              res += 1 - numbers[i];
          }
          else{
               res += numbers[i] + holes[s_temp];
          }
     }

     cout << res << endl;
     
     return 0;
}