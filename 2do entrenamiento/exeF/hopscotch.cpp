#include <unordered_map>
#include <vector>
#include <iostream>    
#include <string> 
#include <climits>

using namespace std;

bool leeNyK(int* n, int* k)
{
    cin >> *n >> *k;

    if (*n > 50)
        return false;
    else if (*k > *n * *n)
        return false;

    return true;
}

unordered_map<int, vector<vector<int> > > leeMatriz(int n)
{
    unordered_map<int, vector< vector<int> > > hopscotch;
    hopscotch.reserve(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<int> pos;
            pos.push_back(i);
            pos.push_back(j);

            int num;
            cin >> num;

            if (hopscotch.find(num) == hopscotch.end())
                hopscotch[num] = vector<vector<int> >();

            hopscotch[num].push_back(pos);
        }
    }

    return hopscotch;
}

int hop(unordered_map<int, vector<vector<int> > > hopscotch, int k)
{
    int hopDist = 0;
    vector<int> tmp;
    unordered_map<int, int> distance, previous;
            
    for (int i = 1; i < k; i++)
    {
        int next = i + 1;

        if (hopscotch.find(i) == hopscotch.end()
            || hopscotch.find(next) == hopscotch.end())
            return -1;

        vector<vector<int> > nextHop = hopscotch[next];
        
        int distance = INT_MAX;

        if (!tmp.empty())
        {
            auto tmp2 = tmp;

            for (auto it2 : hopscotch[next])
            {
                int dist = abs(tmp2[0] - it2[0]);
                dist += abs(tmp2[1] - it2[1]);

                if (dist < distance)
                {
                    distance = dist;
                    tmp = it2;
                }
            }
        }
        else
        {
            for (auto it : hopscotch[i])
            {
                for (auto it2 : hopscotch[next])
                {
                    int dist = abs(it[0] - it2[0]);
                    dist += abs(it[1] - it2[1]);

                    if (dist < distance)
                    {
                        distance = dist;
                        tmp = it2;
                    }
                }
            }
        }
        
        hopDist += distance;
    }

    return hopDist;
}

int main()
{
    int n, k;
    bool res = leeNyK(&n, &k);
    unordered_map<int, vector<vector<int> > > tablero = leeMatriz(n);

    int foo = hop(tablero, k);
    cout << (res ? foo : -1) << endl;
}

