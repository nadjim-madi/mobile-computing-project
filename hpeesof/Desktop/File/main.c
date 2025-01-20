#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
    int donnee;
    struct cellule * suivant;



}*File;

int sommet(File f){
return f->donnee;
}

int estvide(File f){
return f==NULL;
}

File initF(){
return NULL;
}

File defiler(File f){
File l;
l = f.suivant;
free(f);
return l;


}

File enfiler(File f, int n){
File l = f;
File k;
k = (File) malloc(sizeof(File));
k->donnee = n;
k->suivant = NULL;
while(!estvide(l.suivant)){
    l = l.suivant;
}
l.suivant = k;
return f;

}

int estplein(File f){
return 0;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
