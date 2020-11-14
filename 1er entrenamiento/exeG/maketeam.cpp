#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> videos;
int res = 1001;

bool search_answer(vector<int> camino, int costo){
     if(camino.size() == videos.size()){
          if(costo < res){
               res = costo;
          }
          return true;
     }else{
          for(int i = 0; i < videos.size(); i++){
               if(find(camino.begin (), camino.end(), i) == camino.end()){
                    if(costo <= *(videos[i].end() - 1)){
                         for(int j=0; j < videos.size(); j++){
                              if(costo <= videos[i][j]){
                                   camino.push_back(i);
                                   bool temp = search_answer(camino, videos[i][j] + 1);
                                   camino.pop_back();
                                   if(!temp ){
                                        break;
                                   }
                              }
                         }
                    }
               }
          }
     }
     return false;
}


int main(){
     int n;

     cin >> n;

     for(int i=0; i < n; i++){
          videos.push_back({});
          int t;
          cin >> t;
          for(int j=0; j<t; j++){
               int t_i;
               cin >> t_i;
               videos[i].push_back(t_i);
          }
     }

     search_answer({}, 0);

     cout << res << endl;
     return 0;
}