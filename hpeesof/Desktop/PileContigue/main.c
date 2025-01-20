#include <stdio.h>
#include <stdlib.h>
typedef struct {
int hauteur;
int hauteurMax;
int *tab;

}Pile;

int hauteur(Pile p){
return p.hauteur;
}

int sommet(Pile p){
return p.tab[hauteur(p)];
}

int estvide(Pile p){
    return hauteur(p) ==0;
}

int estplein(Pile p){
return hauteur(p) == p.hauteurMax;
}



Pile allocP(int n){
Pile p;
p.hauteurMax = n;
p.tab = (int *) malloc(n*sizeof(int*));
return p;
}

Pile initP(Pile p){
p.hauteur = 0;
return p;

}

Pile empiler(Pile p, int n){
p.hauteur ++;
p.tab[hauteur(p)] = n;
return p;

}

Pile depiler(Pile p){
p.hauteur --;
return p;

}





int main()
{
    printf("Hello world!\n");
    return 0;
}
