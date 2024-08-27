#ifndef OOPTDAVECTOR_INCLUDED
#define OOPTDAVECTOR_INCLUDED

#define MEMALLOCMIN 10

typedef struct{
    void* info;
    unsigned tam;
}tNodo;

typedef struct adtvector{
    tNodo* head;
    unsigned TAM;
    unsigned ce;
    int (*insertAtEnd)(struct adtvector*, void* ele, unsigned tam);
    int (*insertAtTop)(struct adtvector*, void* ele, unsigned tam);
    int (*eq)(struct adtvector*, struct adtvector*);
    void* (*amap)(struct adtvector*, int acc(void*));
    void (*destroy)(struct adtvector*);
} ADTVector;


void* newADTVector();

void destroy(ADTVector* self);
int insertAtEnd(ADTVector* self, void* ele, unsigned tam);
int insertAtTop(ADTVector* self, void* ele, unsigned tam);
int eq(ADTVector* self, ADTVector* other);

void* amap(ADTVector* self, int acc(void*));


#endif // OOPTDAVECTOR_INCLUDED
