#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>
#include "TlmyProducer.h"

int main()
{
    int cont = 0;
    uint8_t buffer[PKT_SIZE];

    while(getPktTlmy(buffer)){
    }

    printf("Total de paquetes: %d", cont);

    return 0;
}
