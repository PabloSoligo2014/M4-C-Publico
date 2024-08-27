#include <stdio.h>
#include <stdlib.h>

#include "OOPTDAVector.h"

int mostrarEntero(void* a){
    return printf("%d ", *(int*)a);
}


int mostrarFlotante(void* a){
    return printf("%5.2f ", *(float*)a);
}


int main()
{
    int i = 0;
    float vec[] = {88.5, 9.33, 16.5, 25.5};

    ADTVector* v1 = newADTVector();
    ADTVector* v2 = newADTVector();

    for(i=0;i<sizeof(vec)/sizeof(vec[0]);i++){
        v1->insertAtEnd(v1, (vec+i), sizeof(vec[i]));
        v2->insertAtEnd(v2, (vec+i), sizeof(vec[i]));
    }

    //v1->insertAtTop(v1, (vec+5), sizeof(vec[5]));

    if(v1->eq(v1, v2)){
        puts("Son iguales");
    }
    v1->amap(v1, mostrarFlotante);


    v1->destroy(v1);

    return 0;
}
