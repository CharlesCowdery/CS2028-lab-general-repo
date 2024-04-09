#include <iostream>
#include "LinearHash.h"
#include "ItemStock.h"

void printMenu() {
    std::cout << "\nMenu:\n"
        << "1. Add Item\n"
        << "2. Remove Item\n"
        << "3. Get Item\n"
        << "4. Get Length\n"
        << "5. Exit\n";
}

int main() {
    LinearHash<ItemStock> hashTable(10);

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int sku;
            std::string description, uom;
            double price, leadTime, quantity;

            std::cout << "Enter SKU: ";
            std::cin >> sku;
            std::cout << "Enter Description: ";
            std::cin.ignore();
            std::getline(std::cin, description);
            std::cout << "Enter Price: ";
            std::cin >> price;
            std::cout << "Enter UOM: ";
            std::cin >> uom;
            std::cout << "Enter Lead Time: ";
            std::cin >> leadTime;
            std::cout << "Enter Quantity On Hand (optional): ";
            std::cin >> quantity;

            ItemStock newItem(sku, description, price, uom, quantity, leadTime);
            try {
                hashTable.AddItem(&newItem);
                std::cout << "Item added to the hash table.\n";
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 2: {
            int sku;
            std::cout << "Enter SKU to remove: ";
            std::cin >> sku;
            ItemStock itemToRemove(sku, "", 0, "");
            ItemStock* removedItem = hashTable.RemoveItem(&itemToRemove);
            if (removedItem) {
                std::cout << "Item removed from the hash table.\n";
            }
            else {
                std::cout << "Item not found in the hash table.\n";
            }
            break;
        }
        case 3: {
            int sku;
            std::cout << "Enter SKU to search: ";
            std::cin >> sku;
            ItemStock itemToSearch(sku, "", 0, "");
            ItemStock* foundItem = hashTable.GetItem(&itemToSearch);
            if (foundItem) {
                std::cout << "Item found in the hash table.\n";
            }
            else {
                std::cout << "Item not found in the hash table.\n";
            }
            break;
        }
        case 4: {
            std::cout << "Number of items in the hash table: " << hashTable.GetLength() << std::endl;
            break;
        }
        case 5:
            std::cout << "Exiting.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}