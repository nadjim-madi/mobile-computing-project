#include <stdio.h>
#include <stdlib.h>



typedef int TElement ;
typedef struct cellule{
 TElement donnee;
 struct cellule *suivant;
 }*Liste;


TElement donnee(Liste l){
    return l->donnee;
}

Liste suivant(Liste l){
return l->suivant;

}

Liste intL(Liste l){
    return NULL;


}

int estVide(Liste l){
return l==NULL;
}


void afficheL(Liste l){

    while(!estVide(l)){
        printf("\n %d",donnee(l));
        l = suivant(l);
    }



}


int longListe(Liste l){
int longe = 0;

while(!estVide(l)){

    longe ++;
    l = suivant(l);

}
return longe;

}



TElement donneeMax(Liste l){
TElement don = donnee(l);
l = suivant(l);
while(!estVide(l)){

    if(donnee(l)> don)
        don = donnee(l);


    l = suivant(l);
}
return don;


}

Liste adresseDonneeMax(Liste l){
Liste p;
p = l;
TElement don = donnee(l);
l = suivant(l);
while(!estVide(l)){

    if(donnee(l)> don){
        don = donnee(l);
        p = l;
    }


    l = suivant(l);
}
return p;


}



Liste inserTete(Liste l, TElement x){
Liste p;
p->donnee = x;
p->suivant = l;
return p;


}

Liste inserQueue(Liste l, TElement x){
Liste p;
Liste premier = l;
l= dernierL(l);
p->donnee =x;
p->suivant =  NULL;
l->suivant = p;
return premier;


}

TElement dernierD(Liste l){
while(!estVide(suivant(l)))
    l = suivant(l);
return donnee(l);

}

Liste dernierL(Liste l){
while(!estVide(suivant(l))){
    l = suivant(l);
    }
return l;

}

Liste suppTete(Liste l){
Liste p;
p= suivant(l);
free(l);
return p;



}

void suppListe(Liste *l) {
    Liste p;

    while (*l != NULL) {
        p = *l;
        *l = suivant(*l);
        free(p);
    }
}


int existDonnee(Liste l, TElement x){
while(!estVide(l)){
    if(x == donnee(l)){
        return 1;
    }
    l = suivant(l);
}
return 0;



}

Liste adresseDonnee(Liste l, TElement x){

while(!estVide(l)){
    if(x == donnee(l)){
        return l;
    }

    l = suivant(l);

}
return NULL;


}

Liste suppQueue(Liste l){
    Liste p = dernierL(l);
    free(p);
    return l;


}
Liste generListe() {
    Liste l = NULL;
    int i;

    for (i = 0; i < 5; ++i) {
    l = inserTete(l,rand() % 100)

    }
    return l;

}



Liste inserPos(Liste l, int e, TElement x){
Liste p=l;
if(e==1){
    return inserTete(l,x);

}
while(e>2 && !estVide(l)){
    l = suivant(l);
    e--;
}
if(e==2)
l->suivant = inserTete(suivant(l),x);


return p;
}




Liste suppPos(Liste l, int e){
Liste p=l;
if(e==1)
    return suppTete(l);
while(e>2 && !estVide(l)){
    l = suivant(l);
    e--;

}
if(e==2)
l.suivant = suppTete(suivant(l));

return p;
}




int main()
{
    printf("Hello world!\n");
    return 0;
}
