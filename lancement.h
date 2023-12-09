#ifndef LANCEMENT_H
#define LANCEMENT_H

#define MAX_CARACTERES 10000

struct messageCesar {
    int cle;
    char texte[MAX_CARACTERES];
    char texteModifie[MAX_CARACTERES];
};

struct messageVigenere {
    char cle[MAX_CARACTERES];
    char texte[MAX_CARACTERES];
    char texteModifie[MAX_CARACTERES];
};

struct messageCesar saisieTexteC(struct messageCesar c);
struct messageVigenere saisieTexteV(struct messageVigenere v);
int choixChiffrementDechiffrement();
int choixAlgorithme();
int choixAlgorithmeDechiffrement();

#endif
