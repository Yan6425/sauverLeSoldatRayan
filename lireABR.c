#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//crée le type ABR stp sinon ça marchera pas

ABR creerABR(int valeur) {
    //à toi mon gars
}

ABR ajouterValeur(ABR arbre, int valeur) {
    //à toi mon gars
}

void lireABR(ABR arbre){
    //à toi mon gars
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
