#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"

Gadget* createGadget(char name[], char brand[], char model[], float price, int quantity) {
    Gadget* newGadget = (Gadget*)malloc(sizeof(Gadget));
    if (newGadget == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    strcpy(newGadget->name, name);
    strcpy(newGadget->brand, brand);
    strcpy(newGadget->model, model);
    newGadget->price = price;
    newGadget->quantity = quantity;
    newGadget->next = NULL;
    return newGadget;
}

void displayGadget(Gadget* gadget) {
    printf("| %-20s | %-20s | %-15s | Rs.%-8.2f | %-8d |\n", gadget->name, gadget->brand, gadget->model, gadget->price, gadget->quantity);
    printf("----------------------------------------------------------------------------------------\n");
}
