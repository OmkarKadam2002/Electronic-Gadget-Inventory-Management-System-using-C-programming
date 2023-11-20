#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"
#include "gadget.h"

Inventory* createInventory() {
    Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));
    if (inventory == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    inventory->head = NULL;
    return inventory;
}

void addGadget(Inventory* inventory, Gadget* newGadget) {
    newGadget->next = inventory->head;
    inventory->head = newGadget;
}

void displayInventory(Inventory* inventory) {
    Gadget* current = inventory->head;
    while (current != NULL) {
        displayGadget(current);
        current = current->next;
    }
}

void swap(Gadget** a, Gadget** b) {
    Gadget* temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Gadget** gadgets, int low, int high, char* sortBy) {
    Gadget* pivot = gadgets[high];
    int i = low - 1;
    int j = low;
    for (j; j < high; j++) {
    	int compareResult = 0;
        if (strcmp(sortBy, "name") == 0) {
            compareResult = strcmp(gadgets[j]->name, pivot->name);
        }
        else if (strcmp(sortBy, "brand") == 0) {
            compareResult = strcmp(gadgets[j]->brand, pivot->brand);
        }
        else if (strcmp(sortBy, "model") == 0) {
            compareResult = strcmp(gadgets[j]->model, pivot->model);
        }
        else if (strcmp(sortBy, "price") == 0) {
			if (gadgets[j]->price < pivot->price) {
				compareResult = -1;
			} 
			else if (gadgets[j]->price > pivot->price) {
                compareResult = 1;
            }
    	}
    	else if (strcmp(sortBy, "quantity") == 0) {
            if (gadgets[j]->quantity < pivot->quantity) {
                compareResult = -1;
            } else if (gadgets[j]->quantity > pivot->quantity) {
                compareResult = 1;
            }
        }
        if (compareResult < 0) {
            i++;
            swap(&gadgets[i], &gadgets[j]);
        }
    }

    swap(&gadgets[i + 1], &gadgets[high]);
    return i + 1;
}


void quicksort(Gadget** gadgets, int low, int high, char* sortBy) {
    if (low < high) {
        int pivotIndex = partition(gadgets, low, high, sortBy);

        quicksort(gadgets, low, pivotIndex - 1, sortBy);
        quicksort(gadgets, pivotIndex + 1, high, sortBy);
    }
}

void sortAndDisplay(Inventory* inventory, char* sortBy) {
    int count = 0;
    Gadget* current = inventory->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    Gadget** gadgets = (Gadget**)malloc(count * sizeof(Gadget*));
    if (gadgets == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    current = inventory->head;
    int i;
    for (i = 0; i < count; i++) {
        gadgets[i] = current;
        current = current->next;
    }

    quicksort(gadgets, 0, count - 1,  sortBy);


    int k;
    printf("Inventory sorted by %s (ascending):\n",  sortBy);
    printf("----------------------------------------------------------------------------------------\n");
	printf("| %-20s | %-20s | %-15s | Rs.$%-8s | %-8s |\n", "Name", "Brand","Model","Price","Quantity");
	printf("----------------------------------------------------------------------------------------\n");
    for (k = 0; k < count; k++) {
        displayGadget(gadgets[k]);
    }

    free(gadgets);
}
