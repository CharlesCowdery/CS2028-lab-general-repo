#include <string>

class ItemStock {
private:
	int sku; //Stock keeping number
	std::string description;
	double price;
	std::string uom; //Unit of measure
	double quantity; //Quantity on hand
	double leadTime; //# of days it takes to order if none on hand

public:
	ItemStock(int Sku, std::string Description, double Price, std::string Uom, double Quantity = 0, double LeadTime);
	std::string getPartInfo();
	double getPrice();
	bool inStock();
	bool isAvailable(int days);

	bool operator >(ItemStock& right);
	bool operator <(ItemStock& right);
	bool operator ==(ItemStock& right);
};