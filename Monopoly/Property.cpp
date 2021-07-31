#include "Property.h"
#include "GameBoard.h"
#include <iostream>
#include <algorithm>

using namespace std;

Property::Property(std::string name, int price, int costPerHouse, 
	int rent0, int rent1, int rent2, int rent3, int rent4, int rent5)
	:Buyable::Buyable(name, price), level{ 0 }, costPerHouse{ costPerHouse }, rents{ rent0, rent1, rent2, rent3, rent4, rent5 }
{
}

int Property::rent(GameBoard* board, Player* player)
{
	return rents[level];
}

int Property::assetPrice()
{
	if (isMortgaged) {
		return price / 2;
	}
	else {
		return price + level * costPerHouse;
	}
}

void Property::viewProperty(Player* a)
{
	cout << *this;
	string input;
	while (true) {
		if (this->isMortgaged) {
			cout << *this;
			cout << "Would you like to [U]nmortgage or [QUIT]? " << endl;
			cin >> input;
			transform(input.begin(), input.end(), input.begin(), ::toupper);
			if (input == "U") {
				if (a->balance >= (this->price / 2)) {
					cout << "Building is now unmortgaged" << endl;
					this->isMortgaged = false;
					a->balance -= (this->price / 2);
					viewProperty(a);
				}
				else {
					cout << "Not enough balance to unmortgage property" << endl;
				}
			}
			else if (input == "QUIT") {
				return;
			}
			else {
				cout << "Invalid input, try again" << endl;
			}
		}
		else {
			cout << *this;
			switch (this->level) {
			case 0:
				while (true) {
					cout << "Would you like to [B]uy or [M]ortgage or [QUIT]" << endl;
					cin >> input;
					transform(input.begin(), input.end(), input.begin(), ::toupper);
					if (input == "B") {
						if (a->balance >= this->costPerHouse) {
							cout << "Bought a house in " << this->name << endl;
							a->balance -= this->costPerHouse;
							this->level++;
						}
						else {
							cout << "You do not have enough balance" << endl;
						}
						break;
					}
					else if (input == "M") {
						a->balance += (this->price / 2);
						this->isMortgaged = true;
						break;
					}
					else if (input == "QUIT") {
						return;
					}
					else {
						cout << "You entered an invalid command." << endl;
					}
				}
				break;
			case 1:
			case 2:
			case 3:
			case 4:
				while (true) {
					cout << "Would you like to [B]uy or [S]ell or [QUIT]" << endl;
					cin >> input;
					transform(input.begin(), input.end(), input.begin(), ::toupper);
					if (input == "B") {
						if (a->balance >= this->costPerHouse) {
							cout << "Bought a house in " << this->name << endl;
							a->balance -= this->costPerHouse;
							this->level++;
						}
						else {
							cout << "You do not have enough balance" << endl;
						}
						break;
					}
					else if (input == "S") {
						a->balance += this->costPerHouse / 2;
						this->level--;
						break;
					}
					else if (input == "QUIT") {
						return;
					}
					else {
						cout << "You entered an invalid command." << endl;
					}
				}
				break;
			case 5:
				while (true) {
					cout << "Would you like to [S]ell or [QUIT]? " << endl;
					cin >> input;
					transform(input.begin(), input.end(), input.begin(), ::toupper);
					if (input == "S") {
						a->balance += this->costPerHouse / 2;
						this->level--;
						break;
					}
					else if (input == "QUIT") {
						return;
					}
					else { cout << "Invalid command" << endl; }
				}
			}
		}
	};
}

void Property::resetProperty()
{
	Buyable::resetProperty();
	this->level = 0;
	this->isMortgaged = false;
}

ostream& operator<<(ostream& out, const Property& c)
{
	out << c.name << endl;
	if (c.isMortgaged) {
		out << "Mortaged" << endl;
	}
	else {
		switch (c.level) {
			case 0:
				out << "You have no house" << endl;
				break;
			case 1:
			case 2:
			case 3:
			case 4:
				out << "You have " << c.level << " houses in this property " << endl;
				break;
			case 5:
				out << "You have a hotel" << endl;
		}
	}
	return out;
}