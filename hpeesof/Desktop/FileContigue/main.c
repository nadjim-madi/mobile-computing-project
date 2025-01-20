#include <stdio.h>
#include <stdlib.h>
typedef struct {
int longeur;
int longeurMax;
int * tab;
}File;


int longeur(File f){
return f.longeur;
}

int estvide(File f){
return longeur(f) == 0;
}

int estplein(File f){
return longeur(f) == f.longeurMax;
}

File allocf(int max){
    File f;
    f.longeurMax = max;
    f.tab = (int*) malloc(max*sizeof(int*));
    return f;
}

int sommet(File f){
return f.tab[1];

}
File enfiler(File f,int n){
f.longeur++;
f.tab[longeur] = n;
return f;


}

File defiler(File f){
int i ;
for(i=1;i<longeur(f);i++){
    f.tab[i-1] = f.tab[i];
}
f.longeur --;
return f;

}
int main()
{
    printf("Hello world!\n");
    return 0;
}
