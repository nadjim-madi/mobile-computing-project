#include <stdio.h>
#include <stdlib.h>
#define DMAX  20
typedef struct {
int degre;
double coef;

}Monome;

typedef struct{
int nbmonome;
Monome tab[DMAX]

}Polynome;

int degremon(Monome m){
return m.degre;
}

double coefmon(Monome m){

return m.coef;
}

Monome iEmeMon(Polynome p,int i){

return p.tab[i];
}
int nbMon(Polynome p){
return p.nbmonome;
}

Polynome initPol(Polynome p){
p.nbmonome = 0;
return p;
}

int estvide(Polynome p){
if(nbMon(p) == 0){
    return 1;
}
return 0;

}

void afficherPol(Polynome p){
int i;
printf("%f x ^ %d", coefmon(iEmeMon(p,0)), degremon(iEmeMon(p,0)));
for(i=1; i<nbMon(p);i++){
    printf(" + %f x ^ %d", coefmon(iEmeMon(p,i)), degremon(iEmeMon(p,i)));


}


}


int plusgrandDeg(Polynome p){

    return degremon(iEmeMon(p,nbMon(p)-1));

}




int main()
{
    printf("Hello world!\n");
    return 0;
}
