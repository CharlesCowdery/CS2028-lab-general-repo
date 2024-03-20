#include "ItemStock.h"
#include <sstream>

using namespace std;

ItemStock::ItemStock(int Sku, std::string Description, double Price, std::string Uom, double Quantity, double LeadTime) {
    sku = Sku;
    description = Description;
    price = Price;
    uom = Uom;
    quantity = Quantity;
    leadTime = LeadTime;
}

std::string ItemStock::getPartInfo() {
    return std::to_string(sku) + " " + description;
}

std::string ItemStock::getFancyInfo() {
    std::stringstream SS;
    SS << "----------------" << endl;
    SS << "| SKU: " << sku << endl;
    SS << "| Description: " << description << endl;
    SS << "| Price: $" << price << endl;
    SS << "| Quantity: " << quantity << "pcs" << endl;
    SS << "| Lead time: " << leadTime << endl;
    SS << "+----------------" << endl;
    return SS.str();
}

double ItemStock::getPrice() {
    return price;
}

bool ItemStock::inStock() {
    return quantity > 0;
}

bool ItemStock::isAvailable(int days) {
    return (quantity > 0) || (days > leadTime);
}

bool ItemStock::operator >(ItemStock& right) {
    return sku > right.sku;
}

bool ItemStock::operator <(ItemStock& right) {
    return sku < right.sku;
}

bool ItemStock::operator ==(ItemStock& right) {
    return sku == right.sku;
}