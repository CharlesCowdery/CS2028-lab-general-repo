#include "ItemStock.h"

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