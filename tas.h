#ifndef TAS_H_
#define TAS_H_

#include "types.h"

int parent(int i);
int gauche(int i);
int droite(int i);

t_tas* initTas(int taille);
void detruireTas(t_tas** tas);

void entasserMax(t_tas* tas, int i);
void construireTasMax(t_tas* tas);

void echanger(t_tas* tas, int i, int j);

// retourne la racine du tas MAX => la plus grande CLE
int maximumTas(t_tas* tas);

// changer la priorité d'une tache, cad la valeur de sa CLE
void augmenterCleTas(t_tas* tas, int i, int cle);
// insére un NOEUD dans le TAS, en respectant la spécificité du TAS
void insererTasMax(t_tas* tas, int cle, char* tache);

// retourne le NOEUD racine du tas, et reconstruit le TAS
void extraireMaxTas(t_tas* tas, int* cleMax, char** tacheMax);

// TAS STOCKANT UN POINTEUR
t_tas_p* initTasP(int taille);
void detruireTasP(t_tas_p** tas);
void entasserMaxP(t_tas_p* tas, int i);
void construireTasMaxP(t_tas_p* tas);
void echangerP(t_tas_p* tas, int i, int j);
int maximumTasP(t_tas_p* tas);
void augmenterCleTasP(t_tas_p* tas, int i, int cle);
void insererTasMaxP(t_tas_p* tas, int cle, char* tache);
void extraireMaxTasP(t_tas_p* tas, int* cleMax, char** tacheMax);

#endif
