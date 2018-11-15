#include <stdlib.h>
#include <stdio.h>
#include "menu.h"

int donnees()
{
    FILE* fichier = NULL;       //

    int caractereActuel;        //déclaration des variables utiles à la fonction donnees
    int compteur;
    int *Tabtemps;
    int *Tabpouls;

    compteur = 1;
    caractereActuel = 0;

    fichier = fopen("Battements.csv", "r");     //Ouverture du fichier

if (fichier != NULL){

    while(caractereActuel != EOF){

        caractereActuel = fgetc(fichier);       //Compteur qui compte le nombre de lignes dans le fichier

        if(caractereActuel == '\n')
            compteur++;
    }
    if(!(Tabtemps = malloc(sizeof(*Tabtemps) * (compteur + 1)))){   //Grace au compteur nous savons le nombre de ligne, donc le nombre de valeur dans chaque tableau
       return(0);
    }
    if(!(Tabpouls = malloc(sizeof(*Tabpouls) * (compteur + 1)))){
        return(0);
    }
    rewind(fichier);

    for(int i = 0; i < compteur; i++){
        fscanf(fichier, "%d;%d", &Tabpouls[i], &Tabtemps[i]);       //Nous placons les valeurs contenu dans le fichier CSV dasn deux tableaux, un pour les pouls, un pour les temps
    }
    fclose(fichier);        //Fermeture du fichier
}
else{
    printf("Impossible d'ouvrir le fichier");
}
menu(Tabpouls,Tabtemps, compteur);      //Nous appelons la fonction menu grace à la bibliothèque menu.h

return 1;
}
