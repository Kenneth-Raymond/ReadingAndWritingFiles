// dataFileTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Inventory.h"
#include <iostream>
#include "string"
#include <stdexcept>
#include <vector>
#include <fstream>
#include <cstdlib>




int main()
{
	int numberOfUnits = 2;
	std::string name = "";
	int qty = 0;
	double perUnit = 0;
	std::vector <Inventory> units(0);
	Inventory testInvetory;
	
	//Ask the user how many units they want to make.
	/*do
	{
		cout << "Please enter how many units you would like. NOTE: Must be at least 5 units" << endl;
			cin >> numberOfUnits;
			if (numberOfUnits < 5)
			{
				cout << "Try again idiot." << endl;
			}//END IF
	}while (numberOfUnits < 5);
	*/

	//User inputs for the units in the order of name, qty, and per unit
	for (int x = 0; x < numberOfUnits; x++)
	{
		std::cout << "Please enter a name for unit #" << x + 1 << "." << std::endl;
		std::cin >> name;
		testInvetory.SetName(name);
		std::cout << "Please enter a Quantity for unit #" << x + 1 << "." << std::endl;
		std::cin >> qty;
		try
		{
			testInvetory.SetQty(qty);
		}
		catch (std::invalid_argument &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Please enter the 'Per Unit' for unit " << x + 1 << "." << std::endl;
		std::cin >> perUnit;
		try 
		{
			testInvetory.SetPerUnit(perUnit);
		}
		catch (std::invalid_argument &e)
		{
			std::cout << e.what() << std::endl;
		}
		units.push_back(testInvetory);
	}

	//WRITING TO THE FILE
	std::ofstream outClientFile("InventoryData.txt", std::ios::out);

	if (!outClientFile)
	{
		std::cerr << "File could not be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	for (Inventory unit : units)
	{
		outClientFile << unit.GetName() << ' ' << unit.GetQty() << ' ' << unit.GetPerUnit() << std::endl;
	}
	outClientFile.close();


	 //READING THE FILE
	std::ifstream inClientFile("InventoryData.txt", std::ios::in);
	if (!inClientFile)
	{
		std::cerr << "File could not be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	while (inClientFile >> name >> qty >> perUnit)
	{
		testInvetory.SetName(name);
		testInvetory.SetQty(qty);
		testInvetory.SetPerUnit(perUnit);
		std::cout << testInvetory.GetName() << ' '  << testInvetory.GetQty() << ' ' << testInvetory.GetPerUnit() << std::endl;
	}
	inClientFile.close();

	system("Pause");
    return 0;
}

