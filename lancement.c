#include "lancement.h"
#include "chiffrement.h"
#include <stdio.h>
#include <string.h>

struct messageCesar saisieTexteC(struct messageCesar c) {
    printf("Entrez le texte : ");
    scanf(" %[^\n]", c.texte);
    getchar();
    return c;
}

struct messageVigenere saisieTexteV(struct messageVigenere v) {
    printf("Entrez le texte : ");
    scanf(" %[^\n]", v.texte);
    getchar();
    return v;
}

int choixAlgorithme() {
    int choixChiffrement;
    do {
        printf("Choix : \n- 0 pour algorithme César \n- 1 pour algorithme Vignenere \n--> ");
        scanf("%d", &choixChiffrement);
    } while (choixChiffrement != 0 && choixChiffrement != 1);
    return choixChiffrement;
}

int choixChiffrementDechiffrement() {
    int choixMode;
    do {
        printf("Choix : \n --> 0 pour chiffre un message \n --> 1 pour déchiffre un message \n --> ");
        scanf("%d", &choixMode);
    } while (choixMode != 0 && choixMode != 1);
    return choixMode;
}
