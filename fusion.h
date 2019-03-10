#ifndef FUSION_H_
#define FUSION_H_

#include "types.h"

// permet de fusionner en un tableau les deux sous tableaux de tab -> tab[p .. q] trié et tab[q+1 .. r] trié en tab[p,r] trié
// avec p <= q < r
void fusion(int* tab, int taille, int p, int q, int r);

#endif
