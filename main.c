#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"
#include "gadget.h"

int linearSearchByName(Inventory* inventory, const char* searchKey){
    Gadget* current = inventory->head;
    int found = 0;

    printf("Search results by name:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-15s | %-10s | %-8s |\n", "Name", "Brand","Model","Price","Quantity");
    printf("----------------------------------------------------------------------------------------\n");
    while (current != NULL) {
        if (strcmp(current->name, searchKey) == 0) {
            displayGadget(current);
            found = 1;
        }
        current = current->next;
    }
    
    return found;
}

int linearSearchByBrand(Inventory* inventory, const char* searchKey) {
    Gadget* current = inventory->head;
    int found = 0;

    printf("Search results by brand:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-15s | %-10s | %-8s |\n", "Name", "Brand","Model","Price","Quantity");
    printf("----------------------------------------------------------------------------------------\n");
    while (current != NULL) {
        if (strcmp(current->brand, searchKey) == 0) {
            displayGadget(current);
            found = 1;
        }
        current = current->next;
    }

    return found;
}

int linearSearchByModel(Inventory* inventory, const char* searchKey) {
    Gadget* current = inventory->head;
    int found = 0;

    printf("Search results by quantity:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-15s | %-10s | %-8s |\n", "Name", "Brand","Model","Price","Quantity");
    printf("----------------------------------------------------------------------------------------\n");
    
    while (current != NULL) {
        if (strcmp(current->model, searchKey) == 0) {
            displayGadget(current);
            found = 1;
        }
        current = current->next;
    }

    return found;
    
}

int linearSearchByQuantity(Inventory* inventory, const char* searchKey) {
    Gadget* current = inventory->head;
    int found = 0;

    printf("Search results by quantity:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-15s | %-10s | %-8s |\n", "Name", "Brand","Model","Price","Quantity");
    printf("----------------------------------------------------------------------------------------\n");
    
    int key = atoi(searchKey);
    while (current != NULL) {
        if (current->quantity == key) {
            displayGadget(current);
            found = 1;
        }
        current = current->next;
    }

    return found;
    
}

void searchGadget(Inventory* inventory) {
    int searchChoice;
    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. Brand\n");
    printf("3. Model\n");
    printf("4. Quantity\n");
    printf("Enter your choice: ");
    scanf("%d", &searchChoice);

    char searchKey[50];
    char temp;
    printf("Enter search key: ");
    scanf("%c",&temp);
    scanf("%[^\n]", searchKey);
    
    switch (searchChoice) {
        case 1:
            linearSearchByName(inventory, searchKey);
            break;

        case 2:
            linearSearchByBrand(inventory, searchKey);
            break;
        
        case 3:
            linearSearchByModel(inventory, searchKey);
            break;
        
	    case 4:
            linearSearchByQuantity(inventory, searchKey);
            break;

        default:
            printf("Invalid search choice. Please enter a valid option.\n");
            return;
    }
    
}

int main() {
    
    Inventory* inventory = createInventory();

    Gadget* gadget1 = createGadget("Smartphone", "Samsung", "Galaxy S21", 999.99, 10);
    Gadget* gadget2 = createGadget("Laptop", "Dell", "XPS 13", 1299.99, 5);
    Gadget* gadget3 = createGadget("Tablet", "Apple", "iPad Air", 499.99, 8);
    Gadget* gadget4 = createGadget("Smartwatch", "Fitbit", "Versa 3", 199.99, 15);
	Gadget* gadget5 = createGadget("Headphones", "Sony", "WH-1000XM4", 349.99, 7);
	Gadget* gadget6 = createGadget("Camera", "Canon", "EOS R5", 3799.99, 3);
	Gadget* gadget7 = createGadget("Fitness Tracker", "Garmin", "Vivosmart 4", 149.99, 12);
	Gadget* gadget8 = createGadget("Gaming Console", "Microsoft", "Xbox Series X", 499.99, 6);
	Gadget* gadget9 = createGadget("Smart Speaker", "Amazon", "Echo Dot", 49.99, 20);
	Gadget* gadget10 = createGadget("Smart TV", "LG", "OLED CX", 1999.99, 4);
	Gadget* gadget11 = createGadget("Wireless Router", "Linksys", "Velop AX5300", 299.99, 9);
	Gadget* gadget12 = createGadget("Smart Thermostat", "Nest", "Learning Thermostat", 249.99, 11);
	Gadget* gadget13 = createGadget("E-reader", "Kobo", "Clara HD", 119.99, 14);
	Gadget* gadget14 = createGadget("Drone", "DJI", "Mavic Air 2", 799.99, 2);
	Gadget* gadget15 = createGadget("VR Headset", "Oculus", "Quest 2", 299.99, 8);


    addGadget(inventory, gadget1);
    addGadget(inventory, gadget2);
    addGadget(inventory, gadget3);
    addGadget(inventory, gadget4);
    addGadget(inventory, gadget5);
    addGadget(inventory, gadget6);
    addGadget(inventory, gadget7);
    addGadget(inventory, gadget8);
    addGadget(inventory, gadget9);
    addGadget(inventory, gadget10);
    addGadget(inventory, gadget11);
    addGadget(inventory, gadget12);
    addGadget(inventory, gadget13);
    addGadget(inventory, gadget14);
    addGadget(inventory, gadget15);

    printf("Inventory:\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-15s | Rs.%-8s | %-8s |\n", "Name", "Brand","Model","Price","Quantity");
    printf("----------------------------------------------------------------------------------------\n");
    displayInventory(inventory);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Display Inventory\n");
        printf("2. Add Gadget\n");
        printf("3. Search for Gadget\n");
        printf("4. Update Gadget Information\n");
        printf("5. Sort and Display Inventory\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	printf("Inventory:\n");
			    printf("----------------------------------------------------------------------------------------\n");
			    printf("| %-20s | %-20s | %-15s | Rs.$%-8s | %-8s |\n", "Name", "Brand","Model","Price","Quantity");
			    printf("----------------------------------------------------------------------------------------\n");
                displayInventory(inventory);
                break;

            case 2: {
                char name[50], brand[50], model[20];
                float price;
                int quantity;

                printf("Enter gadget details:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Brand: ");
                scanf("%s", brand);
                printf("Model: ");
                scanf("%s", model);
                printf("Price: ");
                scanf("%f", &price);
                printf("Quantity: ");
                scanf("%d", &quantity);

                Gadget* newGadget = createGadget(name, brand, model, price, quantity);
                addGadget(inventory, newGadget);
                printf("Gadget added successfully!\n");
                break;
            }
            
            case 3:
                searchGadget(inventory);
                break;
                
            case 4: {
            	char updateName[50];
                printf("Enter the name of the gadget to update: ");
                scanf("%s", updateName);

                Gadget* current = inventory->head;
                while (current != NULL && strcmp(current->name, updateName) != 0) {
                    current = current->next;
                }

                if (current == NULL) {
                    printf("Gadget not found in the inventory.\n");
                } else {
                    float newPrice;
                    int newQuantity;
                    
					printf("Enter updated Price: ");
                    scanf("%f", &newPrice);
                    printf("Enter updated Quantity: ");
                    scanf("%d", &newQuantity);
                    
					current->price = newPrice;
                    current->quantity = newQuantity;

                    printf("Gadget information updated successfully!\n");
                }
				break;
			}
			
			case 5:{
                int sortChoice;
                printf("Sort options:\n");
                printf("1. Sort by Name\n");
                printf("2. Sort by Brand\n");
                printf("3. Sort by Model\n");
                printf("4. Sort by Price\n");
                printf("5. Sort by Quantity\n");
                printf("Enter your sort choice: ");
                scanf("%d", &sortChoice);

                char* sortBy = NULL;

                switch (sortChoice) {
                    case 1:
                        sortBy = "name";
                        break;

                    case 2:
                        sortBy = "brand";
                        break;

                    case 3:
                        sortBy = "model";
                        break;

                    case 4:
                        sortBy = "price";
                        break;

                    case 5:
                        sortBy = "quantity";
                        break;

                    default:
                        printf("Invalid sort choice. Please enter a valid option.\n");
                        continue; 
                }
                
                sortAndDisplay(inventory, sortBy);
                break;
            }
            	

            case 0:
                printf("Exiting program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}




