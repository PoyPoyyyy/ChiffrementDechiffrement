#include "chiffrement.h"
#include "lancement.h"
#include <stdio.h>
#include <string.h>

struct messageCesar dechiffrementCesar(struct messageCesar c) {
    int i = 0;
    while (c.texte[i] != '\0') {
        c.texteModifie[i] = c.texte[i] - c.cle;
        i++;
    }
    c.texteModifie[i] = '\0';
    return c;
}

struct messageVigenere dechiffrementVigenere(struct messageVigenere v) {
    int tailleCle = strlen(v.cle);
    int tailleTexte = strlen(v.texte);
    int i = 0;
    int j = 0;
    while (v.texte[i] != '\0') {
        if (v.texte[i] >= 'A' && v.texte[i] <= 'Z') {
            v.texte[i] = v.texte[i] - 'A' + 'a';
        }
        if (v.texte[i] >= 'a' && v.texte[i] <= 'z') {
            v.texteModifie[i] = 'a' + (v.texte[i] - 'a' - (v.cle[j] - 'a') + 26) % 26;
        }
        else {
            v.texteModifie[i] = v.texte[i];
        }

        i++;
        j = (j + 1) % tailleCle;
    }
    v.texteModifie[tailleTexte] = '\0';
    return v;
}
