#ifndef NOEUD_H_
#define NOEUD_H_

typedef struct noeud_t {
	char* mot;
	struct noeud_t* fils_gauche;
	struct noeud_t* fils_droite;
	struct noeud_t* pere;
} noeud_t;

noeud_t* creerNoeud(char* mot);
void detruireNoeud(noeud_t** noeud);

#endif
