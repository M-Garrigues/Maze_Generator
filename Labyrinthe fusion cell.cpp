#include <iostream>
#include <ctime>
#include <cstdlib>




using namespace std;


int main()
{
    srand(time(NULL));

    int n = 10 , m = 10; //taille

    int nbMurs = 2*m*n-m-n;


    int tabCell[m][n];

    bool murH[m][n-1];
    bool murV[m-1][n];


    for (int i = 0; i != m; i++) //init true
    {
        for (int j = 0; j != n-1; j++)
        {
            murH[i][j] = true;
        }
    }

    for (int i = 0; i != m-1; i++) //init true
    {
        for (int j = 0; j != n; j++)
        {
            murV[i][j] = true;
        }
    }


    int c = 0; //compteur

    for (int i = 0; i != m; i++) //init tableau cellules
    {
        for (int j = 0; j != n; j++)
        {
            tabCell[i][j] = c;
            c++;
        }
    }




    while (nbMurs != (m-1)*(n-1))
    {
        int Xw, Yw, zougloudance; //nombres aléatoires
        bool murEchec = true;

        do //sélection mur depart
        {
            zougloudance = rand()%2;

            if(zougloudance == 0) //mur HORIZONTAL
            {
                    Xw = rand()%(m);

                    Yw = rand()%(n-1);
            }
            else //mur VERTICAL
            {
                    Xw = rand()%(m-1);

                    Yw = rand()%(n);
            }


            if (zougloudance < 1) //Mur HORIZONTAL
            {
                if (tabCell[Xw][Yw+1] != tabCell[Xw][Yw]) murEchec = false;
            }
            else                    //Mur VERTICAL
            {
                if (tabCell[Xw+1][Yw] != tabCell[Xw][Yw]) murEchec = false;
            }

        }while(murEchec); //[Xw][Yw] coordonnées mur choisi.


         //changements de valeurs :

         int max, min;  //on commence par déterminer le min/max des deux cellules voisines.


         if (zougloudance == 0) //Mur HORIZONTAL
            {
               murH[Xw][Yw] = false; //on ouvre le mur.

               if (tabCell[Xw][Yw+1] < tabCell[Xw][Yw])
               {
                   min = tabCell[Xw][Yw+1];
                   max = tabCell[Xw][Yw];
               }
               else
               {
                   min = tabCell[Xw][Yw];
                   max = tabCell[Xw][Yw+1];
               }

            }
            else                    //Mur VERTICAL
            {
                murV[Xw][Yw] = false; //on ouvre le mur.

                if (tabCell[Xw+1][Yw] < tabCell[Xw][Yw])
                {
                   min = tabCell[Xw+1][Yw];
                   max = tabCell[Xw][Yw];
                }
                else
                {
                    min = tabCell[Xw][Yw];
                    max = tabCell[Xw+1][Yw];
                }
            }


                        //puis on remplace toutes les valeurs du max ds le tabCell par le min.

         for (int i = 0; i != m; i++)
        {
            for (int j = 0; j != n; j++)
            {
                if(tabCell[i][j] == max) tabCell[i][j] = min;
            }
        }

        nbMurs--; // et on décrémente le compteur de murs.
    }


    cout<<"Murs verticaux :"<<endl<<endl;

    for (int i = 0; i != m; i++) //affichage tab murs horizontaux.
    {
        for (int j = 0; j != n-1; j++)
        {
            cout<<murH[i][j];
            if(j == n-2) cout<<endl;
        }
    }

    cout<<endl<<endl<<"Murs horizontaux :"<<endl<<endl;
    for (int i = 0; i != m-1; i++) //affichage tab murs verticaux.
    {
        for (int j = 0; j != n; j++)
        {
            cout<<murV[i][j];
           if(j == n-1)cout<<endl;
        }
    }

    return 0;
}




