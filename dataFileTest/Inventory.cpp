
#include "stdafx.h"
#include "Inventory.h"
#include "String"
#include <stdexcept>

using namespace std;
Inventory::Inventory(string name, int qty, double perUnit)
{
	SetName(name);
	SetQty(qty);
	SetPerUnit(perUnit);
}
void Inventory::SetName(string name)
{
	int length = name.size();
		length = (length < 25 ? length : 24);
	name.copy(this->name, length);
	this->name[length] = '\0';
}
string Inventory::GetName()
{
	return name;
}
void Inventory::SetQty(int qty)
{
	if (qty < 0)
	{
		throw invalid_argument("QTY can not be negative");
	}
	this->qty = qty;
}
int Inventory::GetQty()
{
	return qty;
}
void Inventory::SetPerUnit(double perUnit)
{
	if (perUnit < 0)
	{
		throw invalid_argument("QTY can not be negative");
	}
	this->perUnit = perUnit;
}
double Inventory::GetPerUnit()
{
	return perUnit;
}