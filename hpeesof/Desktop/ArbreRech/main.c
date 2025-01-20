#include <stdio.h>
#include <stdlib.h>

typedef struct racine{
    int donne;
    struct racine * filsGauche;
    struct racine * filsDroit;




}*Arbre;





int estVide(Arbre a){
return a == NULL;
}


Arbre initArbre(){
return NULL;
    }

int donne(Arbre a){
return a->donne;
}

Arbre filsG(Arbre a){
return a->filsGauche;

}

Arbre filsD(Arbre a){
return a->filsDroit;

}

Arbre creatFeuille(int elt){
Arbre a;

    a = (Arbre) malloc(sizeof(Arbre));
        a->donne = elt;
        a->filsDroit = NULL;
        a->filsGauche = NULL;
        return a;
}

Arbre minimum(Arbre a){
while(!estVide(filsG(a))){
        a = filsG(a);

}
return a;
}
Arbre maximum(Arbre a){
while(!estVide(filsD(a))){
        a = filsD(a);

}
return a;
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


//PREFIXE
void afficherArbre(Arbre a){
    if(!estVide(a)){
    printf("%d",donne(a));
    afficherArbre(filsG(a));
    afficherArbre(filsD(a));
    }
}



int main()
{
    Arbre a= initArbre();
    a = itinserABR(10,a);
    a = itinserABR(20,a);
    //a = itinserABR(30,a);
    printf("%d ",donne(a));
    //afficherArbre(a);
    return 0;

}
