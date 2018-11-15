#include <stdio.h>
#include <stdlib.h>

int donnees()
{
    FILE* fichier = NULL;
    int caractereActuel;
    int compteur;
    int *Tabtemps;
    int *Tabpouls;
    compteur = 1;
    caractereActuel = 0;
    fichier = fopen("Battements.csv", "r");

if (fichier != NULL){

    while(caractereActuel != EOF){
        caractereActuel = fgetc(fichier);
        if(caractereActuel == '\n')
            compteur++;
    }
    if(!(Tabtemps = malloc(sizeof(*Tabtemps) * (compteur + 1)))){
       return(0);
    }
    if(!(Tabpouls = malloc(sizeof(*Tabpouls) * (compteur + 1)))){
        return(0);
    }
    rewind(fichier);
    for(int i = 0; i < compteur; i++){
        fscanf(fichier, "%d;%d", &Tabpouls[i], &Tabtemps[i]);
    }
    fclose(fichier);
}
else{
    printf("Impossible d'ouvrir le fichier");
}
for(int i = 0 ; i < compteur - 1; i++){
    printf("%d, %d\n",Tabpouls[i],Tabtemps[i]);
}
return 1;
}
