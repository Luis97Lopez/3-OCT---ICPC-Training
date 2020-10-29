#include <iostream>
#include <vector>

using namespace std;

int main(){

     int n, k;
     vector<string> dashboard;
     vector<int> boats;
     int res = 0;

     cin >> n >> k;
     
     for(int i=0; i < n; i++){
          string temp;
          cin >> temp;
          dashboard.push_back(temp);
     }

     for(int i = 0; i < k; i++){
          int temp;
          cin >> temp;
          boats.push_back(temp);
     }

     for(int i = 0; i < boats.size(); i++){
          int times, mod;
          times = n/boats[i];
          mod = n % boats[i];

          if(mod != 0){
               times += mod + 1;
          }

          res += n * (times);
     }

     cout << res << endl;

     return 0;
}