#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Maillon {
    int valeur;
    struct Maillon* plusGrand;
    struct Maillon* plusPetit;
} Maillon;

typedef Maillon* ABR;

ABR creerABR(int valeur) {
    ABR arbre = malloc(sizeof(Maillon));
    arbre->valeur = valeur;
    return arbre;
}

ABR ajouterValeur(ABR arbre, int valeur) {
    if (arbre == NULL) {
        arbre = malloc(sizeof(Maillon));
        arbre->valeur = valeur;
    }
    else if (arbre->valeur < valeur) {
        arbre->plusGrand = ajouterValeur(arbre->plusGrand, valeur);
    }
    else {
        arbre->plusPetit = ajouterValeur(arbre->plusPetit, valeur);
    }
    return arbre;
}

void lireABR(ABR arbre){
    if (arbre == NULL) {
        return;
    }
    lireABR(arbre->plusPetit);
    printf("%d ", arbre->valeur);
    lireABR(arbre->plusGrand);
}

int main(int argc, char** argv){
    if (argc < 2) {
        printf("Erreur d'aguments\n");
        return EXIT_FAILURE;
    }
    ABR arbre = creerABR(atoi(argv[1]));
    for (int i = 2; i < argc; i++) {
        arbre = ajouterValeur(arbre, atoi(argv[i]));
    }
    lireABR(arbre);
    printf("\n");

    return EXIT_SUCCESS;
}
