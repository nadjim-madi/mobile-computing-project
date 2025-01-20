#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int degre;
    double coef;


}Monome;

typedef struct cellule{

    Monome mon;
    cellule * suivant;


}*Polynome;


int degre(Monome m ){
return m.degre;
}

double coef(Monome m){
return m.coef;

}

Monome monome(Polynome p){
return p->mon;


}

Polynome suivant(Polynome p){
return p->suivant;
}


Polynome initPoly(){
    Polynome p = malloc(sizeof(Polynome));
    p = NULL;
    return p;


}

int estVidePoly(Polynome p){
return p==NULL;
}

Polynome inserTete(Monome m, Polynome p){

    Polynome l = initPoly();
    l->mon = m;
    l->suivant =p;
    return l;


}





Polynome inserQueue(Monome m, Polynome p){
Polynome l = initPoly();
Polynome res = p;
l->mon = m;
l->suivant = NULL;
while(!estVidePoly(suivant(p))){
    p= suivant(p);
}
p->suivant = l;

return res;

}

Polynome reinserQueue(Monome m, Polynome p){
    if(estVidePoly(suivant(p))){
        Polynome l = initPoly();
        l->mon = monome;
        l->suivant = NULL;
        p.suivant = l;
        return p;
    }
    else{
            p.suivant = reinserQueue(m,suivant(p));
            return p;

    }


}



Polynome inserMonPoly(Monome m, Polynome p){
Polynome l = p;




if(degre(m) < degre(monome(p)))
        return inserTete(m,p);


while(!estVidePoly(suivant(p)) && degre(m) > degre(monome(suivant(p)))){

    p = suivant(p);

}

p->suivant = inserTete(m,suivant(p));

return l;


}

Polynome reinserMonPoly(Monome m, Polynome p){
    if(estVidePoly(p)){
       return inserTete(m,p);
    }
    if(degre(m) < degre(monome(p))){
        return inserTete(m,p);
    }



    else{
            p->suivant = reinserMonPoly(m,suivant(p));
            return p;


    }

}


Polynome suppTete(Polynome p){
Polynome l;
l = p;
p = suivant(p);
free(l);
return p;
}


Polynome estExistMonPoly(Monome m, Polynome p){

while(!estVidePoly(p)  ){

        if(m.degre == degre(monome(p)) && m.coef == coef(monome(p))){
            return p;
        }

}
return NULL;


}

Polynome reestExistMonPoly(Monome m, Polynome p){
if(estVidePoly(p)){
    return NULL;
}

if(m.degre == degre(monome(p)) && m.coef == coef(monome(p))){
    return p;
}
else{
    return reestExistMonPoly(m,suivant(p));
}


}

Polynome suppMonPoly(Monome m, Polynome p){

Polynome l = p;

if(m.degre == degre(monome(p)) && m.coef == coef(monome(p))){
    return suppTete(p);
}


while(!estVidePoly(suivant(p) ||!(m.degre == degre(monome(suivant(p)) && m.coef == coef(monome(suivant(p))) ){
p = suivant(p);

}
if(suivant(p)!=NULL)
    p.suivant = suppTete(suivant(p));

return l;





}

Polynome resuppMonPoly(Monome m, Polynome p){
        if(estVidePoly(p)){
            return NULL;
        }
        if(m.degre == degre(monome(p) && m.coef == coef(monome(p))){
            return suppTete(p);
}
        else{
            p.suivant = resuppMonPoly(m,suivant(p));
            return p;
        }


}




void delPolynome(Polynome *p){
    while(!estVidePoly(*p)){
        *p = suppTete(*p);
    }


}

void redelPolynome(Polynome *p){
    if(!estVidePoly(*p)){
        *p = suppTete(*p);
        redelPolynome(*p);

    }


}



double maxCoef(Polynome p){
double max = coef(monome(p));
p = suivant(p);
while(!estVidePoly(p)){
    if(coef(monome(p)) > max)
        max = coef(monome(p));

p = suivant(p);

}
return max;


}


double reMaxCoef(Polynome p ){
    if(estVidePoly(suivant(p))){
        return coef(monome(p));
    }
    else{
        return max(coef(monom(p)), reMaxCoef(suivant(p)));
    }

}


double sommecoef(Polynome p){
double somme = 0;
while(!estVidePoly(p)){
    somme += coef(monome(p));


    p = suivant(p);
}

return somme;
}


double reSommeCoef(Polynome p){
if(estVidePoly(suivant(p))){
    return coef(monome(p));
}
else{
    return coef(monome(p)) + reSommeCoef(suivant(p));

}


}


Polynome generPoly(){
int i;
for( i = 0;i>10;i++){
    Monome m;
    m.degre = rand();
    m.coef = rand();
    Polynome p = initPoly();
    Polynome p = inserTete(m,p);

}

return p;
}



void affichePoly(Polynome p){
    while(!estVidePoly(p)){
        printf("degre : ...");



    }



}


void reaffichePoly(Polynome p){
    if(!estVidePoly(p)){
    printf("bla bla bla");
    reaffichePoly(suivant(p));
    }


}


Polynome derivePoly(Polynome p){
Polynome l = initPoly();
Polynome k = l;
if(degre(monome(p)) == 0){
    p = suivant(p);
    k=l;
}
while(!estVidePoly(p)){
    Monome m;
    p.mon.coef= coef(monome(p))* degre(monome(p));
    p.mon.degre= degre(monome(p)) -1 ;
    p = suivant(p);


}

return k;

}

Polynome redirevePoly(Polynome p){
if(p->mon.degre == 0){
    p = suivant(p);
}

if(estVidePoly(p)){
    return NULL;
}

p->mon.coef = p->mon->coef * p->mon->degre;
p->mon.degre --;
p->suivant = rederivePoly(suivant(p));
return p;




}







Liste sommePoly(Polynome p1, Polynome p2){
Liste first;
Liste sm;
first = sm;
double coe;
while(!estVidePoly(p1) && estVidePoly(p2)){
        if(degre(monome(p1)) == degre(monome(p2))){

                Monome m ;
                m.coef = coef(monome(p1)) +  coef(monome(p2));
                sm =inserQueue(m,sm);
                p1 = suivant(p1);
                p2 = suivant(p2);

        }
        if(degre(monome(p1)) > degre(monome(p2))){
            sm = inserQueue(p2->m,p2);
            p2 = suivant(P2);
        }
        else{
            sm = inserQueue(p1->m,p1);
            p1 = suivant(p1);
        }

}





}
int main()
{
    printf("Hello world!\n");
    return 0;



}
