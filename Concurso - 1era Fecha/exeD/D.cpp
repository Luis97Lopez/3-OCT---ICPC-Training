#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int cambios(vector<int> arreglo)
{
    int count = 0;
    int ant = INT_MIN;
    vector<int>::iterator it = arreglo.begin();


    while(it != arreglo.end())
    {
        int valor = *it;

        if (valor < ant)
        {
            vector<int>::iterator it2 = arreglo.begin();     

            while (it2 != arreglo.end() && *it2 < valor)
                it2++;

            count++;
            int valor2 = *it2;
            arreglo.erase(it2);
            arreglo.push_back(valor2);
            ant = INT_MIN;
            it = arreglo.begin();
            

        }
        else
        {
            ant = valor;
            it++;
        }
    }

    return count;
}

int main()
{
    int n;
    vector<int> arreglo;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int foo;
        cin >> foo;
        arreglo.push_back(foo);
    }
    
    int cuenta = cambios(arreglo);
    cout << cuenta << endl;
}