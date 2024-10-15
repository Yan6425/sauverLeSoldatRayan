#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Maillon {
    int valeur;
    struct Maillon* suivant;
} Maillon;

typedef Maillon* Liste;

Liste creerListe(int valeur) {
    Liste liste = malloc(sizeof(Maillon));
    liste->valeur = valeur;
    return liste;
}

Liste ajouterValeur(Liste liste, int valeur) {
    if (liste == NULL) {
        return creerListe(valeur);
    }
    else {
        liste->suivant = ajouterValeur(liste->suivant, valeur);
        return liste;
    }
}

int lireListe(Liste liste, int i){
    if (i) {
        return lireListe(liste->suivant, i - 1);
    }
    else if (liste == NULL) {
        printf("Erreur d'indice\n");
        assert(0);
    }  
    else {
        return liste->valeur;
    }
}

int main(int argc, char** argv){
    if (argc < 3 || atoi(argv[1]) < 0) {
        printf("Erreur d'arguments\n");
        return EXIT_FAILURE;
    }
    Liste liste = creerListe(atoi(argv[2]));
    for (int i = 3; i < argc; i++) {
        liste = ajouterValeur(liste, atoi(argv[i]));
    }
    printf("%d\n", lireListe(liste, atoi(argv[1])));

    return EXIT_SUCCESS;
}
