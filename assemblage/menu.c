#include <stdio.h>
#include <stdlib.h>
#include "action.h"

int menu(int *Tabpouls,int *Tabtemps,int compteur)  //Cette fonction sert à savoir le choix de l'utilisateur, suite a ce choix nous appelons les fonctions contenu dans action.c
{
    int menu, temps, min, max;

    printf("afficher ordre CSV = 0\nsouhaitez vous triez les valeurs = 1\nréaliser une moyenne des valeurs = 2\nrecherchez des valeurs = 3\nconnaitre le nombre de lignes = 4\npour finir le minimum et le maximum de pouls = 5\n");
    scanf("%d", &menu);

    switch(menu){

    case 0:
        trie(menu, Tabpouls, Tabtemps);
    break;

    case 1:
        trie(menu, Tabpouls, Tabtemps);
    break;

    case 2:
        moyenne(Tabpouls, Tabtemps, compteur);
    break;

    case 3:
        printf("Pour quelle valeur de temps voulez vous le pouls\n");
        scanf("%d", &temps);
        dichotomie(Tabtemps, Tabpouls, temps, compteur);
    break;

    case 4:
        printf("le nombre de ligne du CSV est : %d \n", compteur - 1);
    break;

    case 5:
        min = minimum(Tabpouls, compteur - 2);
        max = maximum(Tabpouls, compteur - 1);
        printf("le minimum est : %d\n", Tabpouls[min]);
        printf("le maximum est : %d\n", Tabpouls[max]);
    break;
    }
}
