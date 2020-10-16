#include<iostream>

using namespace std;

bool isFilenameValid(string filename, string submittedFile)
{
    bool res = false;
    auto it = submittedFile.find_last_of('/');
    string substring = submittedFile.substr(it, submittedFile.length() - 1);



    return res;
}

int main()
{
    string filename, submittedFile;
    int r, d, e, c, t;

    cin >> filename;
    cin >> submittedFile;
    cin >> r >> d >> e;
    cin >> c;

    string correctLines[c];

    for (int i = 0; i < c; i++)
        cin >> correctLines[i];
    
    cin >> t;

    string submittedLines[t];

    for (int i = 0; i < t; i++)
        cin >> submittedLines[i];
}

