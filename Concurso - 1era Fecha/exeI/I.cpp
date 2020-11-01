#include<iostream> 
#include<algorithm>
#include <vector>

using namespace std;


int checkpass(string s) {
    int r = 0;
    bool a = false, b = false, c = false, d = false, e = false;

    for (char ch : s) {
        if (!a && ch >= 97 && ch <= 122) {
            a = true;
            r++;
        }
        if (!b && ch >= 64 && ch <= 90) {
            b = true;
            r++;
        }
        if (!c && ch >= 48 && ch <= 57) {
            // al menos un digito
            c = true;
            r++;
        }
        if (!d && ((ch >= 35 && ch <= 38) || (ch >= 46 && ch <= 47) || (ch >= 40 && ch <= 41))) {
            // caracter especial
            d = true;
            r++;
        }
    }

    if (s.size() >= 10)
        r++;

    int di;
    if (c)
    {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                di = s[i] - 48;
                if (s[i + 1] - 48 == di + 1) {
                    r--;
                    return r;
                }
                /*for (int j = i + 1; j < s.size(); j++) {
                    if (s[j] - 48 == di + 1) {
                        r--;
                        return r;
                    }
                }*/
            }
        }
    }

    return r;
}

int main()
{
    int t;

    cin >> t;

    vector<string> ps;
    int res[t];
    for (int i = 0; i < t; i++) {
        string temp;
        cin >> temp;
        ps.push_back(temp);
        res[i] = 0;//checkpass(temp);
    }

    for (int i = 0; i < t; i++)
        res[i] = checkpass(ps[i]);

    for (int i = 0; i < t; i++)
    {
        if (res[i] == 5) {
            cout << "Assertion number #" << i + 1 << ": Strong" << endl;
        }
        else if (res[i] == 4) {
            cout << "Assertion number #" << i + 1 << ": Good" << endl;
        }
        else if (res[i] == 3) {
            cout << "Assertion number #" << i + 1 << ": Weak" << endl;

        }
        else {
            cout << "Assertion number #" << i + 1 << ": Rejected" << endl;
        }
    }
}