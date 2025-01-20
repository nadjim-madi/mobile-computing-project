#include <stdio.h>
#include <stdlib.h>

Polynome interPoly(Polynome p1, Polynome p2){
Polynome p3;

int i = 0;
int j =0;
int k = 0;
int c;
while(i<p1.nbMon && j < p2.nbMon){
    if(p1.tab[i].degre == p2.tab[j].degre){
        c= p1.tab[i] + p2.tab[j];
        p3.tab[i] = c;
        i++;
        j++;
        if(c != 0){
            k++;
        }

    }
    else if (p1.tab[i].degre >p2.tab[j].degre){
        i++;
    }
    else {
        j++;
    }

p3.nbMon = k;
return p3;

}




}



int main()
{
    printf("Hello world!\n");
    return 0;
}
