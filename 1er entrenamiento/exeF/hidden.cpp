#include <iostream>
#include <set>
#include <vector>

const unsigned int M = 1000000007;

using namespace std;


vector<vector<int>> getArray(string sub, string full){
    int i_sub = 0, i_full = 0;
    vector<vector<int>> total = {};
    vector<int> temp = {};

    while(true){
        if(i_full < full.size() && i_sub < sub.size()){
            if(sub[i_sub] == full[i_full]){
                temp.push_back(i_full);
                if(++i_sub == sub.size()){
                    total.push_back(temp);
                }
            }
            i_full++;
        }
        else{
            if(--i_sub == -1)
                break;
            i_full = temp.back() + 1;
            temp.pop_back();
        }
    }

    return total;
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
                        res = res + 1;
                    }
               }
          }
     }
     return res % M;
}

bool is_valid(int length1, int length2, int length3, int lengthT){
    return (length1 + length2 + length3) == lengthT;
}


int main(){
    string s1, s2, s3, sGlobal;

    cin >> s1;
    cin >> s2;
    cin >> s3;
    cin >> sGlobal;

    if(!is_valid(s1.size(), s2.size(), s3.size(), sGlobal.size())){
        cout << 0 << endl;
        return 0;
    }
    
    vector<vector<int>> array1 = getArray(s1,sGlobal);
    vector<vector<int>> array2 = getArray(s2,sGlobal);
    vector<vector<int>> array3 = getArray(s3,sGlobal);
    //cout << getNumberCombinations(array1, array2, array3, sGlobal.size()) << endl;
    return 0;
}


/*

aaaaaaaaaaaaaa
bbbbbbbbbbbbbb
cccccccccccccc
abcabcabcabcabcabcabcabcabcabcabcabcabcabc


*/