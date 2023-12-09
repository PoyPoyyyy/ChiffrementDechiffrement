#include "lancement.h"
#include "chiffrement.h"
#include "dechiffrement.h"
#include "sauvegarde.h"
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 255

int main(void) {
    int choixChiffrement;
    int choixDechiffrement;
    int cle;
    int choixMode;
    struct messageCesar c;
    struct messageVigenere v;
    int continuer = 1;

    do {
        printf("\n- Lancement de l'application -\n");
        choixChiffrement = choixAlgorithme();

        switch (choixChiffrement) {
            case 0: { // Algorithme César
                printf("\n- Lancement chiffrement par algorithme de César -\n");
                choixMode = choixChiffrementDechiffrement();
                switch (choixMode) {
                    case 0: { // Chiffrement César
                        printf("\n- Chiffrement -\n");
                        c = saisieTexteC(c);
                        printf("Quelle est la valeur de la clé de chiffrement : ");
                        scanf("%d", &c.cle);
                        c = chiffrementCesar(c);
                        sauvegardeFichierCesar(c);
                        printf("Message chiffré : %s\n", c.texteModifie);
                        break;
                    }

                    case 1: { // Déchiffrement César
                        printf("\n- Déchiffrement -\n");
                        c = saisieTexteC(c);
                        printf("Quelle est la valeur de la clé de déchiffrement: ");
                        scanf("%d", &c.cle);
                        c = dechiffrementCesar(c);
                        sauvegardeFichierCesar(c);
                        printf("Message déchiffré : %s", c.texteModifie);
                        break;
                    }
                }
                break;
            }
            case 1: { // Algorithme Vigenere
                printf("\n- Lancement chiffrement par algorithme de Vigenere -\n");
                choixMode = choixChiffrementDechiffrement();
                switch (choixMode) {
                    case 0: { // Chiffrement Vigenere
                        printf("\n- Chiffrement -\n");
                        v = saisieTexteV(v);
                        printf("Entrez la clé de chiffrement : ");
                        scanf(" %[^\n]", v.cle);
                        v = chiffrementVigenere(v);
                        sauvegardeFichierVigenere(v);
                        printf("Message chiffré : %s\n", v.texteModifie);
                        break;
                    }

                    case 1: { // Dechiffrement Vigenere
                        printf("\n- Déchiffrement -\n");
                        v = saisieTexteV(v);
                        printf("Entrez la clé de déchiffrement : ");
                        scanf(" %[^\n]", v.cle);
                        v = dechiffrementVigenere(v);
                        sauvegardeFichierVigenere(v);
                        printf("Message déchiffré : %s", v.texteModifie);
                        break;
                    }
                }
                break;
            }
        }

        printf("\nVoulez-vous continuer (1 pour Oui / 0 pour Non) ? ");
        scanf("%d", &continuer);

    } while (continuer);

    return 0;
}