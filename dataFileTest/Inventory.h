#pragma warning(disable:4996)
#include "string"

class Inventory
{
public:
	//Default parameters constr
	explicit Inventory(std::string = "", int = 0, double = 0);
	//GETTERS AND SETTERS
	void SetName(std::string);
	std::string GetName();
	void SetQty(int);
	int GetQty();
	void SetPerUnit(double);
	double GetPerUnit();
private:
	char name[25];
	int qty;
	double perUnit;
};

