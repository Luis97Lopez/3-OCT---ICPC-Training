#include <unordered_set>
#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
     int n;
     cin >> n;
     unordered_set<string> set;
     for(int i=0; i < n; i++)
     {
          string temp;
          cin >> temp;
          set.insert(temp);
     }
     cout << set.size() << endl;
}