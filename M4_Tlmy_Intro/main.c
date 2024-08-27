#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include "TlmyProducer.h"

#define HARDCODE_PKTS_COUNT 3

//Esta funcion no deberia estar aqui
int showHex(void* ele);
//Esta funcion no deberia estar aqui
void* map(void* vec, unsigned nelements, unsigned esize, int action(void* ele));


int main()
{

    uint8_t buffer[PKT_SIZE];
    int i;

    for(i=0;i<HARDCODE_PKTS_COUNT;i++){
        if (getPktTlmy(buffer)){
            //Muestro solo los 20 primeros
            map(buffer, /*PKT_SIZE*/20, sizeof(uint8_t), showHex);
            puts("");
        }
    }
    return 0;
}

//Esta funcion no deberia estar aqui
int showHex(void* ele){
    uint8_t* pele = (uint8_t*)ele;
    return printf("%04X ", *pele);
}

//Esta funcion no deberia estar aqui
void* map(void* vec, unsigned nelements, unsigned esize, int action(void* ele)){
    int i;
    void* ini = vec;
    for(i=0;i<nelements;i++){
        action(vec);
        vec++;
    }
    return ini;
}

