#include <iostream> /* pour les flux cout et cin      */
#include <string>   /* pour les chaînes de caractères */
#include <vector>   /* pour les tableaux de valeurs   */
#include <iomanip>  /* pour la fonction setw()        */
using namespace std;

bool estPremier(int nombre) /*fonction qui permet de vérifier si un nombre est premier*/
{
    for (int i = 1; i < nombre; i++) /*On vérifie la division du nombre par i, soit tout les entiers allant de 1 au nombre*/
    {
        if (nombre % i == 0
            && i != 1) return false; /*On renvoie 0 car le nombre est divisible par i*/
    }
    return true; /*On renvoie 1 car le nombre n'est divisible que par 1 et lui même*/
}

int main(void)
{
    vector<int> facteurs;
    int nombre = 0; /*On initialise nos variables*/
    cout << "Choisissez un nombre a decomposer: ";
    cin >> nombre; /*On lit le nombre*/
    const int ESPACE = to_string(nombre).length(); /*permet de calculer le nombre de chiffre du nombre choisis*/
    while (nombre != 1)
    {
        for (int i = 2; i <= nombre; i++)
        {
            if (estPremier(i) && nombre % i == 0) /*On teste si i est premier et si le nombre est divisible par i*/
            {
                cout << setw(ESPACE) << nombre << " | " << i << endl; /*On affiche le nombre et son diviseur*/
                nombre = nombre / i; /*On divise le nombre*/
                facteurs.push_back(i); /*on ajoute le diviseur à la liste des facteurs*/
            }
        }
    }
    cout << setw(ESPACE) << 1 << " |" << endl << "= "; /*On affiche le dernier diviseur, en l'occurence 1*/
    for (size_t i = 0; i < facteurs.size(); i++)
        cout << facteurs[i] << (char)(i < facteurs.size()-1 ? '*' : ' '); /*On affiche la liste des facteurs sous forme de multiple = f1*f2... */
    return EXIT_SUCCESS;
}