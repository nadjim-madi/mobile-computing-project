#include <stdio.h>
#include <stdlib.h>
typedef struct Monome{
int degre;
double coef;


}Monome;
typedef struct Poly {
Monome monomes[100];
int nbmon;
}Poly;


int degre(Monome m){
return m.degre;
}

double coef(Monome m){
return m.coef;
}

Monome iEmeMon(Poly p,int i){
return p.monomes[i];
}

Poly initPoly(){
Poly p;
p.nbmon = 0;
return p;
}

int estVide(Poly p){
return p.nbmon == 0;
}

int estPlein(Poly p){
return p.nbmon == 100;

}

int plusGrandDeg(Poly p){
return p.monomes[p.nbmon -1];


}

double plusGrandCoef(Poly p){
int i;
double max = p.monomes[0];
for(i=1;i<p.nbmon;i++){
    if(p.monomes[i].coef > max){
        max = p.monomes[i].coef;
    }



}
return max;

}

double evalPoly(Poly p, double x){
int i;
double res = 0;
for(i=0;i<p.nbmon;i++){
    res = res + p.monomes[i].coef * pow(x,p.monomes[i].degre);

}
return res;



}
Poly derivee(Poly p){
int i=1;
if(p.monomes[0].degre == 0){
    for(i=1;i<p.nbmon;i++){
        p.monomes[i-1].coef = p.monomes[i].coef;
        p.monomes[i-1].degre = p.monomes[i].degre;

    }
    p.nbmon--;
}
for(i=0;i<p.nbmon;i++){

    p.monomes[i].coef =  p.monomes[i].coef *  p.monomes[i].degre;
     p.monomes[i].degre--;

}

return p;


}


Poly sommePoly(Poly p1, Poly p2){
    Poly somme;

    int i=0;
    int j=0;
    int k = 0;

    while(i<p1.nbmon && j< p2.nbmon){
        if(p1.monomes[i].degre == p2.monomes[j].degre ){

        }
        else{

        }

    }


}



int main()
{
    printf("Hello world!\n");
    return 0;
}
