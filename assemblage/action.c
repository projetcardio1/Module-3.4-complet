#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int *valeur1, int *valeur2){

int temp;

temp = *valeur1;            //Fonction utile pour le trie, sert à échanger deux valeurs dans un tableau
*valeur1 = *valeur2;
*valeur2 = temp;

}

int maximum(int tab[], int taille)
{
	int i = 0, indice_max = taille;

	while (i != taille)
	{
		if (tab[i] > tab[indice_max])       //fonction qui trouve le maximum dans un tableau
		{
			indice_max = i;
		}
		i++;
	}
	return indice_max;
}

int minimum(int tab[], int taille)
{
	int i = 0, indice_max = taille;

	while (i != taille)
	{
		if (tab[i] < tab[indice_max])       //Fonction qui trouve le minimum dans un tableau
		{
			indice_max = i;
		}
		i++;
	}
	return indice_max;
}

void tri_selection(int tab[], int tab2[], int taille, int ordre)
{
	int res, taille2;

	taille2 = taille - 1;

	if (ordre == 0) {       //Trie ordre croissant des pouls

		for (int i = 0; i < taille; i++)
		{
			res = maximum(tab, taille2);
			swap(&tab[res], &tab[taille2]);     //Trie par selection, il cherche le maximum dans le tableau et le place dans la derniere case du tableau
			swap(&tab2[res], &tab2[taille2]);   //De plus, il bouge les elements de l'autre tableau pour que les valeurs soit toujours associe à leur temps
			taille2--;
		}
	}
	else if (ordre == 1) {      //Trie ordre decroissant des pouls

		for (int i = 0; i < taille; i++) {
			res = minimum(tab, taille2);
			swap(&tab[res], &tab[taille2]);     //Trie les pouls ordre decroissant bouge leur temps associe
			swap(&tab2[res], &tab2[taille2]);
			taille2--;
		}
	}else if (ordre == 2){      //Trie ordre decroissant des temps

	    for(int i = 0; i < taille; i++){
            res = minimum(tab2, taille2);
            swap(&tab2[res], &tab2[taille2]);       //Trie les temps puis les pouls associe à ces temps
            swap(&tab[res], &tab[taille2]);
            taille2--;
	}
	}
}

int trie(int menu2,int tab[],int tab2[])
{
	int taille = 12, menu;

	if (menu2 == 0){

	for(int i = 0; i < taille; i++){
        printf("%d, %d\n",tab[i], tab2[i]);
	}
	}else{
	printf("tri ordre croissant des pouls = 0, tri odre decroissant pouls = 1, decroissant temps = 2\n");
	scanf("%d", &menu);

	tri_selection(tab, tab2, taille, menu);

	for (int i = 0; i < taille; i++)
	{
		printf("%d, %d\n", tab[i], tab2[i]);
	}
	}
	return 0;
}

int dichotomie(int tab[], int tab2[], int temps,int taille)
{                                                           //Recherche dichotomique dasn des tableaux
    int gauche, droite, middle;
    bool trouve = false;

    gauche = 0;
    droite = taille -1;

    while(trouve != true && gauche <= droite){

    middle = (gauche + droite) / 2;

    if (tab[middle] == temps){

    trouve = true;                              //Cherche l'indice du tableau ou la valeur chercher se trouve

    }else{

    if(temps > tab[middle]){

    gauche = middle + 1;

    }else{

    droite = middle - 1;
    }
}
}
    if(trouve == true){

    printf("la valeur du pouls qui correspond au temps %d est %d\n", temps, tab2[middle]);      //affiche l'indice du tableau a laquelle la valeur a ete trouvee
    }else{

    printf("la valeur %d n'est pas dans tableau", temps);
    }
    return middle;      //Retourne l'indice du tableau (utile pour la moyenne)
}

int moyenne(int Tabpouls[],int Tabtemps[], int taille)
{
    int moyenne = 0, temps, temps2, id_temps, id_temps2;

    printf("entre quelle valeur du temps voulez vous réalisez la moyenne du pouls ?\n");
    scanf("%d %d", &temps, &temps2);

    id_temps = dichotomie(Tabtemps, Tabpouls, temps, taille);   //Cherche l'indice du temps dans le tableau

    id_temps2 = dichotomie(Tabtemps, Tabpouls, temps2, taille);

    for (int i = id_temps; i <= id_temps2; i++){        //Calcul la moyenne des pouls entre les indices des temps trouve grace a la dichotomie
        moyenne = moyenne + Tabpouls[i];
    }
    moyenne = moyenne / (id_temps2 - id_temps + 1);
    printf("la moyenne est : %d", moyenne);

    return 0;
}
