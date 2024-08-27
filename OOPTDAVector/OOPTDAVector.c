#include <stdlib.h>
#include <string.h>

#include "OOPTDAVector.h"

//TDA Vector: El codigo es TDA vector pero se le pone
//este nombre para no generar conflicto entre los alumnos
//y la asignatura
void* newADTVector(){
    ADTVector* self = malloc(sizeof(ADTVector));
    if(!self){
        return NULL;
    }

    self->TAM = MEMALLOCMIN;
    self->head    = malloc(sizeof(tNodo)*self->TAM);

    if(!self->head){
        free(self);
        return NULL;
    }
    self->ce      = 0;
    self->insertAtEnd   = insertAtEnd;
    self->insertAtTop   = insertAtTop;
    self->destroy       = destroy;
    self->eq            = eq;
    self->amap = amap;
    return self;

}



void destroy(ADTVector* self){
    int i;
    tNodo* ln = self->head;
    for(i=0;i<self->ce;i++){
        free(ln->info);
        ln++;
    }
    free(self->head);
    free(self);
}

int insertAtTop(ADTVector* self, void* ele, unsigned tam){
    void* ninfo;
    tNodo* nh;


    if(self->ce==self->TAM){
        //Redimensionar
        //realloc or malloc?
        nh = malloc(sizeof(tNodo)*((self->ce)+MEMALLOCMIN));
        if(!nh){
            return 0;
        }
        memcpy(nh, self->head, sizeof(tNodo)*self->ce);
        free(self->head);
        self->head = nh;
        self->TAM = (self->ce)+MEMALLOCMIN;

    }
    ninfo = malloc(tam);
    if(!ninfo){
        return 0;
    }

    //new place at the beginning
    memcpy(self->head+1, self->head, sizeof(tNodo)*self->ce);
    //cpy new info
    memcpy(ninfo, ele, tam);
    self->head->info = ninfo;
    self->head->tam = tam;
    self->ce++;
    return 1;
}

int insertAtEnd(ADTVector* self, void* info, unsigned tam){
    void* ninfo;
    tNodo* nh;
    tNodo* fin;

    if(self->ce==self->TAM){
        //Redimensionar
        //realloc or malloc?
        nh = malloc(sizeof(tNodo)*((self->ce)+MEMALLOCMIN));
        if(!nh){
            return 0;
        }
        memcpy(nh, self->head, sizeof(tNodo)*self->ce);
        free(self->head);
        self->head = nh;
        self->TAM = (self->ce)+MEMALLOCMIN;

    }
    ninfo = malloc(tam);
    if(!ninfo){
        return 0;
    }
    fin = self->head+self->ce;

    memcpy(ninfo, info, tam);
    fin->info = ninfo;
    fin->tam = tam;
    self->ce++;
    return 1;
}

void* amap(ADTVector* self, int acc(void*)){
    int i;
    tNodo* ln = self->head;
    for(i=0;i<self->ce;i++){
        acc(ln->info);
        ln++;
    }
    return self;

}

int eq(ADTVector* self, ADTVector* other){
    int i;
    tNodo* ln1 = self->head;
    tNodo* ln2 = other->head;
    if (self->ce!=other->ce){
        return 0;
    }

    for(i=0;i<self->ce;i++){
        if (ln1->tam!=ln2->tam){
            return 0;
        }else{
            if (memcmp(ln1->info, ln2->info, ln1->tam)!=0){
                return 0;
            }
        }

    }
    return 1;
}

