#include <iostream>
#include <string>  
#include <vector>  
#include <iomanip> 
using namespace std;

int main(void)
{
    vector<int> facteurs;
    int nombre = 0; 
    cout << "Choisissez un nombre a decomposer: ";
    cin >> nombre; 
    const int ESPACE = to_string(nombre).length(); 
    while (nombre != 1)
    {
        for (int i = 2; i <= nombre; i++)
        {
            if (nombre % i == 0) 
            {
                cout << setw(ESPACE) << nombre << " | " << i << endl;
                nombre = nombre / i;
                facteurs.push_back(i);
            }
        }
    }
    cout << setw(ESPACE) << 1 << " |" << endl << "= "; 
    for (size_t i = 0; i < facteurs.size(); i++)
        cout << facteurs[i] << (char)(i < facteurs.size()-1 ? '*' : ' ');
    return EXIT_SUCCESS;
}