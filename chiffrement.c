#include "chiffrement.h"
#include "lancement.h"
#include <stdio.h>
#include <string.h>

struct messageCesar chiffrementCesar(struct messageCesar c) {
    int i = 0;
    while (c.texte[i] != '\0') {
        c.texteModifie[i] = c.texte[i] + c.cle;
        i++;
    }
    c.texteModifie[i] = '\0';
    return c;
}

struct messageVigenere chiffrementVigenere(struct messageVigenere v) {
    int tailleCle = strlen(v.cle);
    int tailleTexte = strlen(v.texte);

    for (int i = 0; i < tailleTexte; i++) {
        if (v.texte[i] >= 'A' && v.texte[i] <= 'Z') {
            v.texte[i] = v.texte[i] - 'A' + 'a';
        }
        if (v.texte[i] >= 'a' && v.texte[i] <= 'z') {
            int decalage = (v.cle[i % tailleCle] - 'a');
            v.texteModifie[i] = 'a' + (v.texte[i] - 'a' + decalage) % 26;
        }
        else {
            v.texteModifie[i] = v.texte[i];
        }
    }

    v.texteModifie[tailleTexte] = '\0';
    return v;
}