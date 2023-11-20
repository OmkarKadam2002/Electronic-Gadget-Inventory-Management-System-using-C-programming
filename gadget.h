#ifndef GADGET_H
#define GADGET_H

typedef struct Gadget {
	char name[50];
    char brand[50];
    char model[50];
    float price;
    int quantity;
    struct Gadget* next; 
} Gadget;

Gadget* createGadget(char name[], char brand[], char model[], float price, int quantity);
void displayGadget(Gadget* gadget);

#endif
