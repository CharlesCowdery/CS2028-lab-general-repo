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
    std::string getPartInfo();
    std::string getFancyInfo();
    double getPrice();
    bool inStock();
    bool isAvailable(int days);


    bool operator > (ItemStock& right);
    bool operator < (ItemStock& right);
    bool operator == (ItemStock& right);
};