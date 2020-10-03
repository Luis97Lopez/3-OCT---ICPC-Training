#include <iostream>
#include <vector>
using namespace std;

void addRow(vector<vector<int>> &array, int length){
     vector<int> row;
     for(int i = 0; i < length; i++){
          row.push_back(0);
     }
     array.push_back(row);
}

void checkIfNeedMoreRows(vector<vector<int>> &array, int length, int n){
     int difference = n - array.size() + 1;
     if(difference > 0){
          for(int i = 0; i < difference; i++){
               addRow(array, length);
          }
     }
}

bool canBeInserted(vector<vector<int>> &array, int length, int x, int y, int horizontal, int vertical){
     for (int i = 0; i < vertical; i++){
          checkIfNeedMoreRows(array, length, y + i);
          for(int j = 0; j < horizontal; j++)
               if(array[y + i][x + j] == 1)
                    return false;
     }
     for(int i = array.size() - 1; i >= y; i--)
          for(int j = 0; j < horizontal; j++)
               if(array[i][x + j] == 1)
                    return false;
     return true;
}

void fillArray(vector<vector<int>> &array, int x, int y, int horizontal, int vertical){
     for (int i = 0; i < vertical; i++){
          for(int j = 0; j < horizontal; j++)
               array[y + i][x + j] = 1;
     }
}

void insertBlock(vector<vector<int>> &array, int length, int horizontal, int vertical, int position){
     if(array.size() == 0){
          checkIfNeedMoreRows(array, length, vertical);
          fillArray(array, position, 0, horizontal, vertical);
     }
     else{
          int level = 0;
          while(true){
               if(canBeInserted(array, length, position, level, horizontal, vertical)){
                    fillArray(array, position, level, horizontal, vertical);
                    break;
               }
               else{
                    level++;
               }
          }
     }
}

int get_result(vector<vector<int>> array, int length)
{
     int i = array.size() - 1;
     for(; i >= 0; i--){
          for(int j = 0; j < length; j++){
               if(array[i][j] == 1){
                    return i + 1;
               }
          }
     }
}

int main ()
{
     int r, length;
     cin >> length >> r;

     vector<vector<int>> array;

     for(int i= 0; i < r; i++){
          int h, v, c;
          cin >> h >> v >> c;
          insertBlock(array, length, h, v, c - 1);
     }
     cout << get_result(array, length) << endl;
}