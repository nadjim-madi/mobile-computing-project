#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
    cellule* suivant;
    int sommet;


}*Pile;


int sommet(Pile p){
return p->sommet;
}



int estVide(Pile p){
    return p == NULL;


}

Pile empiler(int d, Pile p){
Pile l = malloc(sizeof(cellule));
l->sommet = d;
l->suivant = p;
return l;


}
Pile initPile(Pile p){
return NULL;

}

Pile depiler(Pile p){

Pile l = p;
p = suivant(p);
free(l);
return p;


}

int estPlein(Pile p){
return 0;
}




int main()
{
    printf("Hello world!\n");
    return 0;
}
