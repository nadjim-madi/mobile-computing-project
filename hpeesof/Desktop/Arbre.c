#include <stdio.h>
#include <stdlib.h>
typedef struct Noeud{
    int donnee;
    struct Noeud *filsD;
    struct Noeud *filsG;

}*Arbre;

int donnee(Arbre a){
    return a->donnee;
}

Arbre filsGauche(Arbre a){
    return a->filsG;
}
Arbre filsDroit(Arbre a){
    return a->filsD;
}

Arbre createNoeud(int n, Arbre fg, Arbre fd){
    Arbre a = (Arbre)malloc(sizeof(Arbre));
    a->filsG = fg;
    a->filsD = fd;
    a->donnee = n;
    return a;
}

Arbre createFeuille(int n){
    Arbre a = (Arbre) malloc(sizeof(Arbre));
    a->donnee = n;
    a->filsD = NULL;
    a->filsG = NULL;
    return a;
}
Arbre initA(){
    return NULL;
}

int estVideA(Arbre a){
    return a==NULL;
}
int estFeuille(Arbre a){
    return estVideA(filsDroit(a)) && estVideA(filsGauche(a));
}

void parcoursPost(Arbre a){
    if(!estVideA(a)){
        parcoursPost(filsGauche(a));
        parcoursPost(filsDroit(a));
        printf("%d",donnee(a));
    }
}

int tailleArbre(Arbre a){
    if(estVideA(a))
    return 0;

    return 1+ tailleArbre(filsG(a)) + tailleArbre(filsDroit(a));
}


int nbFeuille(Arbre a){
    if(estVideA(a)){
        return 0;
    }
    if(estFeuille(a))
    return 1;

    return nbFeuille(filsGauche(a)) + nbFeuille(filsDroit(a));
}

int recherchelem(Arbre a, int elem){
    if(estVideA(a))
        return 0;
    
    if(elem==donnee(a))
        return 1;

    if(recherchelem(filsGauche(a),elem))
        return 1;
    return recherchelem(filsDroit(a),elem);

}

int max(int a , int b){
    if(a>b)
    return a;
return b;
}

int hauteur(Arbre a){
    if(estVideA(a))
        return 0;
    if(estFeuille(a))
        return 1;
    int h1 = 1 + hauteur(filsGauche(a));
    int h2 = 1+ hauteur(filsDroit(a));
    return max(h1,h2);
}

void suppA(Arbre *a){
    if(!estVideA(*a)){
        parcoursPost(filsGauche(*a));
        parcoursPost(filsDroit(*a));
        free(*a);
        
    }
}

int sommeA(Arbre a){
    if(estVideA(a))
        return 0;

    return donnee(a) + sommeA(filsGauche(a)) + sommeA(filsDroit(a));
}


int occurrence(int elem, Arbre a){
    if(estVideA(a))
        return 0;
    if(elem == donnee(a))
        return 1+ occurrence(filsGauche(a)) + occurrence(filsDroit(a));
    return occurrence(filsGauche(a)) + occurrence(filsDroit(a));



}


int recherchelemAB(int elem, Arbre a){
    if(estVideA(a))
        return 0;
    
    if(elem == donnee(a))
        return 1;
    if(elem>donnee(a))
        return recherchelem(filsDroit(a));
    return recherchelem(filsGauche(a));




}

int minAbrbin(Arbre a){
    while(!estVideA(filsGauche(a)))
        a = filsGauche(a);

    return donnee(a);
}

Arbre inserElt(int elem, Arbre a){
    if(estVideA(a))
        return createFeuille(elem);

    if(elem>donnee(a)){
    a->filsD = inserElt(elem,filsDroit(a));
    return a;
    }
    else{
    a->filsG = inserElt(elem,filsGauche(a));
    return a;

    }

}

Arbre maxArBin(Arbre a){
if(estVideArbre(filsDroit(a))){
    return a;
}
else{
    return maxArBin(filsDroit(a));
}


}
Arbre supprimeRacine(Arbre a){
Arbre b;
if(!estVideArbre(filsGauche(a))){
    b = filsGauche(a);
    Arbre max = maxArBin(b);
    max ->filsDroit = filsDroit(a);
}
else{
    b = filsDroit(a);
    Arbre min = minArbBin(b);
    b->filsGauche = filsGauche(a);
}
free(a);
return b;


}



int main(){




}
