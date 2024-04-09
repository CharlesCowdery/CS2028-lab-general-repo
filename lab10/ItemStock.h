#pragma once
#include <string>

class ItemStock {
private:
    int sku;
    std::string description;
    double price;
    std::string uom;
    double quantity;
    double leadTime;

public:
    ItemStock(int Sku, std::string Description, double Price, std::string Uom, double Quantity = 0, double LeadTime = 0);
    int getSKU() const;
    std::string getPartInfo() const;
    bool operator>(const ItemStock& right) const;
    bool operator<(const ItemStock& right) const;
    bool operator==(const ItemStock& right) const;
};