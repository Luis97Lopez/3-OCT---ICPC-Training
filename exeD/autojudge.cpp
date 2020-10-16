#include<iostream>

using namespace std;

bool isFilenameValid(string filename, string submittedFile)
{
    bool res = false;
    auto it = submittedFile.find_last_of('/');
    
    if (it != -1)
        submittedFile = submittedFile.substr(it + 1, submittedFile.length());
    
    auto pos2 = submittedFile.find_last_of('.');
    
    if (pos2 == -1)
        return false;

    string extension = submittedFile.substr(pos2, submittedFile.length());

    if (extension.compare(".c") == 0 || extension.compare(".cpp") == 0
        || extension.compare(".java") == 0 || extension.compare(".py") == 0)
    {
        res = true;

        if (filename.compare(submittedFile.substr(0, pos2 - 1)) == 0)
            res = true;
        else
            res = false;
    }

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

    isFilenameValid(filename, submittedFile);
}