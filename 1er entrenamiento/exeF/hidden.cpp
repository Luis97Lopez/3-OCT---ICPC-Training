#include <iostream>
#include <set>
#include <vector>
#include <string>

const unsigned int M = 1000000007;

using namespace std;

bool is_valid(int length1, int length2, int length3, int lengthT){
    return (length1 + length2 + length3) == lengthT;
}


string string1, string2, string3, sGlobal;

int search(string::iterator s1, string::iterator s2, string::iterator s3, string::iterator s0){
    int res = 0;
    if(s0 == sGlobal.end()){
        if(s1 == string1.end() && s2 == string2.end() && s3 == string3.end())
            return 1;
        else
            return 0;
    }else{
        if(s1 != string1.end() && *s1  == *s0){
            res += search(s1 + 1, s2, s3, s0 + 1);
        }
        if(s2 != string2.end() && *s2  == *s0){
            res += search(s1, s2 + 1, s3, s0 + 1);
        }
        if(s3 != string3.end() && *s3  == *s0){
            res += search(s1, s2, s3 + 1, s0 + 1);
        }
    }
    return res;
}



int main(){

    cin >> string1;
    cin >> string2;
    cin >> string3;
    cin >> sGlobal;

	if(!is_valid(string1.size(), string2.size(), string3.size(), sGlobal.size())){
        cout << 0 << endl;
        return 0;
    }

    cout << search(string1.begin(), string2.begin(), string3.begin(), sGlobal.begin()) % M << endl;
    return 0;
}
