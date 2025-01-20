#include <stdio.h>
#include <stdlib.h>
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

void parcourPostfixe(Arbre a){
    if(!estVideArbre(a)){
    parcourPostfixe(filsGauche(a));
    parcourPostfixe(filsDroit(a));
    printf("%d", donnee(a));

    }
}
void parcourPrefixe(Arbre a){
    if(!estVideArbre(a)){
    printf("%d", donnee(a));
    parcourPostfixe(filsGauche(a));
    parcourPostfixe(filsDroit(a));

    }
}
void parcourInfixe(Arbre a){
    if(!estVideArbre(a)){
    parcourPostfixe(filsGauche(a));
    printf("%d", donnee(a));
    parcourPostfixe(filsDroit(a));

    }
}


int tailleArbre(Arbre a){
    if(estVideArbre(a)){
        return 0;
    }

    return 1+tailleArbre(filsGauche(a)) + tailleArbre(filsDroit(a));


}


int nbFeuille(Arbre a){
if(estFeuille(a)){
    return 1;
}
else{
    return 0 + nbFeuille(filsGauche(a)) + nbFeuille(filsDroit(a));
}

}

int rechercheElem(int elem, Arbre a){
if(estVideArbre(a)){
    return 0;

}
else if(elem == donnee(a)){
    return 1;
}
else{
    if(rechercheElem(elem,filsGauche(a)))
        return 1;
    else
        return rechercheElem(elem,filsDroit(a));

        }


}
int max(int a, int b){
if(a>b)
    return a;

return b;

}
int hauteur(Arbre a){
if(estVideArbre(a)){
    return 0;
}
if(estFeuille(a)){
    return 1;
}
else{
    int h1 = hauteur(filsDroit(a));
    int h2 = hauteur(filsGauche(a));
    return 1+max(h1,h2);
}
}


void suppArbre(Arbre *a){
if(!estVideArbre(*a)){
    suppArbre(filsGauche(a));
    suppArbre(filsDroit(a));
    free(*a);
}




}


int sommeArbre(Arbre a){
if(estFeuille(a)){
    return donnee(a);
}
else{
    return donnee(a) + sommeArbre(filsGauche(a)) + sommeArbre(filsDroit(a));
}


}
int min(int a, int b){
if(a<b)
    return a;
return b;


}

int plusPetit(Arbre a){
if(estVideArbre(a)){
    return 0;
}

else{
    return min (donnee(a),min(plusPetit(filsGauche(a)), plusPetit(filsDroit(a))));
}


}

int occurrence (int elem, Arbre a){
if(estVideArbre(a))
    return 0;

else{
    if(elem == donnee(a)){
        return 1+ occurrence(filsGauche(a)) + occurrence(filsDroit(a));
    }
    else{
             return 0+ occurrence(filsGauche(a)) + occurrence(filsDroit(a));

    }
}



}


int rechercheElemArbin(int elem,Arbre a){
int trouve = 0;
while(!estVideArbre(a)){
    if(elem ==donnee(a)){
        trouve = 1;

    }
    else{
        if(elem> donnee(a)){
            a = filsDroit(a);
        }
        else{
            a = filsDroit(a);
        }
    }
}

return trouve;




}
Arbre adresseIns(int elt, Arbre a){

    if(elt>donne(a)){
        if(!estVide(filsD(a))){
            return adresseIns(elt,filsD(a));
        }
        else{
            return a;
        }
    }


    else{
        if(!estVide(filsG(a))){
            return adresseIns(elt,filsG(a));
        }
        else{
            return a;
        }
    }
}



Arbre itinserABR(int elt, Arbre a){
Arbre f;

    f = creatFeuille(elt);
   // printf("ijafijaoij\n");
    if(estVide(a)){
            return f;
        }
    printf("qiuefhiauh");
    Arbre adr = adresseIns(elt,a);
    printf("%d", donne(adr));

    if(elt> donne(adr)){
        adr->filsDroit = f;
    }
    else{
        adr->filsGauche = f;
    }


    return a;
}


int minArbBin(Arbre a){
if(estVideArbre(filsGauche(a))){
    return donnee(a);
}
else{
    return minArbBin(filsGauche(a));
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

void fusionArbres(Arbre *c,Arbre a, Arbre b){

if(!estVideArbre(a)){
    *c = itinserABR(donnee(a),a);
    fusionArbres(c,filsGauche(a),b);
    fusionArbres(c,filsDroit(a),b);

    if(!estVideArbre(b)){
    *c = itinserABR(donnee(b),b);
    fusionArbres(c,a,filsGauche(b));
    fusionArbres(c,a,filsDroit(b));
    }
}




}

int* trierTab(int tab[],int n ){
Arbre a;
for(int i = 0;i<n;i++){
    a = itinserABR(tab[i],a);
}

int * tableautrie = (int *) malloc(n*sizeof(int*));
//on fait la fonction de infixe sur le tableau et on remplis le nouveau tableau


//on retourne tableautrie;



return tableautrie;
}


void afficherLargeur(Arbre a){

    File f;
    f = enfiler(f,a);
    while(!estvide(f)){
        a = sommet(f);
        f = defiler(f);
        printf("%d", donnee(a));
        if(!estVideArbre(filsGauche(a)))
            f = enfiler(f,filsGauche(a));

        if(!estVideArbre(filsDroit(a)))
            f = enfiler(f,filsDroit(a));

    }






}






int main(){
    17, 7, 19, 5, 2, 8, 13, 20, 29, 11, 4, 33, 9, 6, 12, 16, 4, 3, 18
    Arbre n17,n7,n5,n2,n4,n8,n13,n11,n19,n20,f3,f9,f12,f16,f33,f6,f18;
    f3 = createFeuille(3);
    f9 = createFeuille(9);
    f12 = createFeuille(12);
    f16 = createFeuille(16);
    f33 = createFeuille(33);
    f6 = createFeuille(6);
    f18 = createFeuille(18);

    n4 = createNoeud(4,f3,NULL);
    n2 = createNoeud(2,NULL,n4);
    n5 = createNoeud(5,n2,f6);
    n11 = createNoeud(11,f9,f12);
    n13 = createNoeud(13,n11,f16);
    n20 = createNoeud(20,NULL,f33);
    n19 = createNoeud(19,f18,n20);
    n8 = createNoeud(8,NULL,n13);
    n7 = createNoeud(7,n5,n8);
    n17 = createNoeud(17,n7,n19);

    //Arbre f0 = createFeuille(0);
    //Arbre f3 = createFeuille(3);
    //Arbre f4 = createFeuille(4);
    //Arbre f1 = createFeuille(1);
    //Arbre f2 = createFeuille(2);
    //Arbre f7 = createFeuille(7);

    //Arbre n13 = createNoeud(13,NULL,f0);
    //Arbre n6 = createNoeud(6,n13,f3);
    //Arbre n8 = createNoeud(8,n6,f2);
    //Arbre n9 = createNoeud(9,f4,f1);
    //Arbre n5 = createNoeud(5,f7,n9);


    //Arbre racine = createNoeud(10,n8,n5);

    printf("%d", rechercheElem(0,f0));

    return 0;
}
