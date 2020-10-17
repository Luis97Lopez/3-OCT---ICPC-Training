#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> getArray(string w, string p){
     int lo = -1;
    vector<vector<int>> set;

    int ws = w.size();
    for(int i = 0; i < w.size(); i++){
        for(int j = 0; j < p.size(); j++){
            if(w[i] == p[j]){
                vector<int> v;
                v.push_back(j);
                i++;
                lo = j;
                for(int k = lo + 1; k < p.size(); k++) {
                    if(i == ws) {
                        set.push_back(v);
                        break;
                    }
                    if(w[i] == p[k]) {
                        v.push_back(k);
                        i++;
                    }
                    //cout << k << "\n";
                }
                i = 0;
                j = lo;
            }
        }
        i = w.size() + 1;
    }

    return set;
}

int getNumberCombinations(    vector<vector<int>> array1, 
                              vector<vector<int>> array2, 
                              vector<vector<int>> array3,  
                              int length){
     set<int> check;
     int res = 0;

     for(int i =0; i < array1.size(); i++){
          for(int j = 0; j < array2.size(); j++){
               for(int k = 0; k < array3.size(); k++){
                    check = {};
                    check.insert(array1[i].begin(), array1[i].end());
                    check.insert(array2[j].begin(), array2[j].end());
                    check.insert(array3[k].begin(), array3[k].end());

                    if(check.size() == length){
                         res++;
                    }
               }
          }
     }
     return res;
}

int main(){
     string s1, s2, s3, sGlobal;

     cin >> s1;
     cin >> s2;
     cin >> s3;
     cin >> sGlobal;
     
     vector<vector<int>> array1 = getArray(s1,sGlobal);
     vector<vector<int>> array2 = getArray(s2,sGlobal);
     vector<vector<int>> array3 = getArray(s3,sGlobal);
     
     cout << getNumberCombinations(array1, array2, array3, 3) << endl;
}