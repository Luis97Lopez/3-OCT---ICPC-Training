#include<iostream>
#include<string>

using namespace std;

string *readLines(int *num)
{
    cin >> *num;
    cin.clear();
    cin.ignore(10000,'\n');

    string lines[*num];

    for (int i = 0; i < *num; i++)
        getline(cin, lines[i]);

    return lines;
}

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

        if (filename.compare(submittedFile.substr(0, pos2)) == 0)
            res = true;
        else
            res = false;
    }

    return res;
}

bool isExecutable(int r)
{
    bool res = true;

    if (r != 0)
        res = false;

    return res;
}

bool isRunnable(int d, int e)
{
    if (d < 1 || d > 10)
        return false;

    if (e < 0 || d > 20)
        return false;

    if (e > d)
        return false;

    return true;
}


bool hasValidOutput(string correctLines[], int c, string generatedLines[], int t)
{
    bool res = c == t;

    for (int i = 0; i < c && res; i++)
        res = generatedLines[i].compare(correctLines[i]) == 0;

    return res;
}

int main()
{
    string filename, submittedFile;
    int r, d, e, c, t;

    getline(cin, filename);
    getline(cin, submittedFile);
    cin >> r >> d >> e;
    string *correctLines = readLines(&c);
    string *submittedLines = readLines(&t);

    if (!isFilenameValid(filename, submittedFile))
    {
        cout << "Compile Error" << endl;
        return 0;
    }

    if (!isExecutable(r))
    {
        cout << "Run-Time Error" << endl;
        return 0;
    }

    if (!isRunnable(d, e))
    {
        cout << "Time Limit Exceeded" << endl;
        return 0;
    }

    if (!hasValidOutput(correctLines, c, submittedLines, t))
        cout << "Wrong Answer" << endl;
    else
        cout << "Correct" << endl;

    return 0;
}