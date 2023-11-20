#ifndef INVENTORY_H
#define INVENTORY_H

#include "gadget.h"

typedef struct Inventory {
    Gadget* head; 
} Inventory;

Inventory* createInventory();
void addGadget(Inventory* inventory, Gadget* newGadget);
void displayInventory(Inventory* inventory);

void swap(Gadget** a, Gadget** b);
int partition(Gadget** gadgets, int low, int high, char* sortBy);
void quicksort(Gadget** gadgets, int low, int high, char* sortBy);
void sortAndDisplay(Inventory* inventory, char* sortBy);
#endif

