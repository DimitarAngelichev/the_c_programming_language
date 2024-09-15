#include <stdio.h>
#include <stdlib.h>

typedef struct state_t {  
        int current;  
        int final;  
        delta_t *deltas;  // Pointer to the deltas[] table  
        void *ctx;  // use this to pass data to the callback  
} state_t;

typedef struct delta_t{
     int current;
        int event;
        int next;
        //callback_t callback;
} delta_t;

void state_constructor(state_t *state, int Initial, int Final, delta_t *Deltas, void *Context);

int main(){
    state_t *statevar = NULL;
    //statevar = malloc(sizeof(state_t));
    
    printf("%d", statevar->current);
    return 0;
}

void state_constructor(state_t *state, int Initial, int Final, delta_t *Deltas, void *Context){
    state = malloc(sizeof(state_t));

    state->current = Initial;
    state->final = Final;
    //allocate memory for Deltas
    Deltas = malloc(sizeof(Deltas));
    state->deltas = Deltas;
    //allocate memory for Context
    Context = malloc(sizeof(Context));
    state->ctx = Context;
}