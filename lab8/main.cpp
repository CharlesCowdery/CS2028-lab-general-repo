#include <iostream>
#include "OrdList.h"
#include "ItemStock.h"

void printMenu() {
    std::cout << "\nMenu:\n"
        << "1. Add Item\n"
        << "2. Check if Item is in List\n"
        << "3. Check if List is Empty\n"
        << "4. Get Size of List\n"
        << "5. See Next Item\n"
        << "6. See Previous Item\n"
        << "7. See Item at Location\n"
        << "8. Remove Next Item\n"
        << "9. Remove Previous Item\n"
        << "10.Print List\n"
        << "0. Exit\n";
}

int main() {
    OrdList<ItemStock> itemList;

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
            std::cin.ignore(); // Ignore newline character left in the buffer
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
            itemList.addItem(newItem);
            break;
        }
        case 2: {
            int sku;
            std::cout << "Enter SKU to check: ";
            std::cin >> sku;
            if (itemList.inList(ItemStock(sku, "", 0, ""))) {
                std::cout << "Item is in the list.\n";
            }
            else {
                std::cout << "Item is not in the list.\n";
            }
            break;
        }
        case 3: {
            if (itemList.isEmpty()) {
                std::cout << "List is empty.\n";
            }
            else {
                std::cout << "List is not empty.\n";
            }
            break;
        }
        case 4: {
            std::cout << "Size of list: " << itemList.size() << std::endl;
            break;
        }
        case 5: {
            try {
                std::cout << "Next item: " << itemList.seeNext().getPartInfo() << std::endl;
            }
            catch (ListUnderflowException& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 6: {
            try {
                std::cout << "Previous item: " << itemList.seePrev().getPartInfo() << std::endl;
            }
            catch (ListUnderflowException& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 7: {
            int location;
            std::cout << "Enter location: ";
            std::cin >> location;
            try {
                std::cout << "Item at location " << location << ": " << itemList.seeAt(location).getPartInfo() << std::endl;
            }
            catch (ListUnderflowException& e) {
                std::cerr << e.what() << std::endl;
            }
            catch (std::out_of_range& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 8: {
            try {
                itemList.removeNext();
                std::cout << "Next item removed.\n";
            }
            catch (ListUnderflowException& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 9: {
            try {
                itemList.removePrev();
                std::cout << "Previous item removed.\n";
            }
            catch (ListUnderflowException& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 10: {
            itemList.printList();
        }
        case 0:
            std::cout << "Exiting.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}