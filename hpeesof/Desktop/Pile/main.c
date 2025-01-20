#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{

int sommet;
struct cellule * suivant;



}*Pile;


int sommet(Pile p){

return p->sommet;
}

int estvidep(Pile p){
return p==NULL;
}

Pile initP(Pile p){
return NULL;
}


Pile allocP(){
Pile p ;
p= (Pile) malloc(sizeof(Pile));
return p;

}


Pile empiler(Pile p,int n){
Pile l;
l=allocP();
l->suivant = p;
return l;


}

Pile depiler(Pile p){
Pile l = p->suivant;
free(p);
return l;

}

void afficher(Pile p){
while(!estvidep(p)){

    printf("%d\n", sommet(p));
    p = depiler(p);
}



}



//T'ES NUL

int main()
{
        Pile p;
        p = empiler(p,10);
        p = empiler(p,50);
        p = empiler(p,30);
        afficher(p);
        return 0;
}
