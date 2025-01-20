#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
 int donnee;
 struct noeud *filsG, *filsD;
}*Arbre ;

int estvide(Arbre a){
return a==NULL;
}
int donnee(Arbre a){
return a->donnee;
}

Arbre filsDroit(Arbre a){
return a->filsD;
}
Arbre filsGauche(Arbre a){
return a->filsG;
}

int estFeuille(Arbre a){
return (a->filsD ==NULL && a->filsG==NULL);

}

int occurence(Arbre a, int elem){
if(estvide(a)){
    return 0;
}
else{
    if(elem == donnee(a)){
        return 1+ occurence(filsGauche(a),elem) + occurence(filsDroit(a),elem);
    }
    else{
        return  occurence(filsGauche(a),elem) + occurence(filsDroit(a),elem);
    }
}

}

int ayant1Fils(Arbre a){
if(estFeuille(a)){
    return 0;
}
else{
    if(estvide(filsDroit(a)) || estvide(filsGauche(a))){
        //parcours prefixe
        return 1+ ayant1Fils(filsGauche(a)) + ayant1Fils(filsDroit(a));
    }
    else{
        return ayant1Fils(filsGauche(a)) + ayant1Fils(filsDroit(a));

    }
}


}






int main()
{
    printf("Hello world!\n");
    return 0;
}
