#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//crée le type Liste stp sinon ça marchera pas

Liste creerListe(int valeur) {
    //à toi mon gars
}

Liste ajouterValeur(Liste liste, int valeur) {
    //à toi mon gars
}

int lireListe(Liste liste, int i){
    //à toi mon gars
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
