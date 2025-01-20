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

Pile allocP(int n){
Pile p ;
p= (Pile) malloc(sizeof(Pile));
p->sommet = n;
return p;

}

Pile empiler(Pile p,int n){
Pile l;
l=allocP(n);
l->suivant = p;
return l;


}

Pile depiler(Pile p){
Pile l = p->suivant;
free(p);
return l;

}
typedef struct Noeud{
int donnee;
struct Noeud * filsGauche;
struct Noeud * filsDroit;

}*Arbre;

int donnee(Arbre a){
return a->donnee;
}

Arbre filsGauche(Arbre a){
return a->filsGauche;
}

Arbre filsDroit(Arbre a){
return a->filsDroit;
}

Arbre createNoeud(int donnee, Arbre fg, Arbre fd){
    Arbre a = (Arbre) malloc(sizeof(Arbre));
    a->donnee = donnee;
    a->filsGauche = fg;
    a->filsDroit = fd;
    return a;

}

Arbre createFeuille(int donnee){
Arbre a = (Arbre) malloc(sizeof(Arbre));
a->donnee = donnee;
a->filsDroit = NULL;
a->filsGauche = NULL;
return a;
}

Arbre initArbre(){
return NULL;
}

int estVideArbre(Arbre a){
return a==NULL;
}

int estFeuille(Arbre a){
return (estVideArbre(filsDroit(a)) && estVideArbre(filsGauche(a)));

}


int occurrence(Arbre a, int elt){
if(estVideArbre(a)){
    return 0;
}
else{
    if(elt==donnee(a)){
        return 1 + occurrence(filsGauche(a)) + occurrence(filsDroit(a));
    }
    else{
         return occurrence(filsGauche(a)) + occurrence(filsDroit(a));
    }
}


}



void itparcours(Arbre a){
Pile p;
p = empiler(p,a);
while(!estvidep(p)){
    printf("%d",donnee(sommet(p)));
    p = depiler(p);

    if(!estVideArbre(filsDroit(a))){
        p = empiler(p,filsDroit(a));
    }
    if(!estVideArbre(filsGauche(a))){
        p = empiler(p,filsGauche(a));
    }
    a = sommet(p);

}



}


int estEquilibre(Arbre a){
    if(estVideArbre(a)){
        return 0;
    }
    else{
        if(estpaire(donnee(a))){
            return 1 + estEquilibre(filsGauche(a)) + estEquilibre(filsDroit(a));
        }
        else{
            return estEquilibre(filsGauche(a)) + estEquilibre(filsDroit(a)) -1 ;

        }
    }



}

void contruireAbr(Arbre a, Arbre *b){
if(!estVideArbre(a)){
    contruireAbr(filsGauche(a));
    *b = inserElt(donnee(a));
    contruireAbr(filsDroit(a));
}


}


int main()
{
    printf("Hello world!\n");
    return 0;
}
