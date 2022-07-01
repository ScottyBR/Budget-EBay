#include "User.h"
#include "Sale.h"

User::User() {
	balance = 1000;
}

void User::setfName(std::string fname) {
	firstName = fname;
}

void User::setlName(std::string lname) {
	lastName = lname;
}

void User::setAddress(std::string ad) {
	address = ad;
}

void User::setNumber(int n) {
	phoneNumber = n;
}

void User::setBalance(float n) {
	balance += n;
}

std::string User::getfName() {
	return firstName;
}

std::string User::getlName() {
	return lastName;
}

std::string User::getAddress() {
	return address;
}

int User::getNumber() {
	return phoneNumber;
}

float User::getBalance() {
	return balance;
}

void User::updateInfo() {
	int input = -1;

	//get valid input
	while (input < 0 || input > 4) {
		std::cout << "Enter 1 to change first name" << std::endl;
		std::cout << "Enter 2 to change last name" << std::endl;
		std::cout << "Enter 3 to change address" << std::endl;
		std::cout << "Enter 4 to change phone number" << std::endl;
		std::cout << "Enter 0 to quit" << std::endl;
		std::cin >> input;

		std::string str;
		switch (input) {
			case 0:
				return;
			case 1:
				std::cout << "Enter new first name: " << std::endl;
				std::cin >> str;
				this->setfName(str);
				break;
			case 2:
				std::cout << "Enter new last name: " << std::endl;
				std::cin >> str;
				this->setlName(str);
				break;
			case 3:
				std::cout << "Enter new address: " << std::endl;
				std::cin >> str;
				this->setAddress(str);
				break;
			case 4:
				std::cout << "Enter new phone number: " << std::endl;
				int num;
				std::cin >> num;
				this->setNumber(num);
				break;
		}
	}
}

//view all unsold products
void User::viewProducts(std::vector<Product*> all_p) {
	int num = 1;
	for (Product* p : all_p) {
		if (!p->isSold()) {
			std::cout << num << ": ";
			p->printProduct();
			num += 1;
		}
	}
}

//view products of the category
void User::viewSimilar(std::vector<Product*> all_p) {
	std::string input;
	std::cout << "What category would you like to see?" << std::endl;
	std::cout << "Technology, Furniture, Clothing, Toy, Health" << std::endl;
	std::cin >> input;

	int num = 1;
	for (Product* p : all_p) {
		if (input == p->stringType()) {
			std::cout << num << ": ";
			p->printProduct();
			num += 1;
		}
	}
}

Seller::Seller(std::string f, std::string l, std::string ad, int phone) {
	setfName(f);
	setlName(l);
	setAddress(ad);
	setNumber(phone);
}

//get interaction from user
void Seller::getInteraction(std::vector<Product*> all_p) {
	int input = -1;

	//get valid input
	while (input < 0 || input > 6) {
		std::cout << "Enter 1 to post product" << std::endl;
		std::cout << "Enter 2 to close bidding on product" << std::endl;
		std::cout << "Enter 3 to view similar products" << std::endl;
		std::cout << "Enter 4 to view all products" << std::endl;
		std::cout << "Enter 5 to update account information" << std::endl;
		std::cout << "Enter 6 to check balance" << std::endl;
		std::cout << "Enter 0 to quit" << std::endl;
		std::cin >> input;
		std::cout << std::endl;

		switch (input) {
			case 0:
				return;
			case 1:
				this->postProduct(&all_p);
				std::cout << std::endl;
				break;
			case 2:
				this->closeBid(&all_p);
				std::cout << std::endl;
				break;
			case 3:
				this->viewSimilar(all_p);
				std::cout << std::endl;
				break;
			case 4:
				this->viewProducts(all_p);
				std::cout << std::endl;
				break;
			case 5:
				this->updateInfo();
				std::cout << std::endl;
				break;
			case 6:
				std::cout << "Balance: " << this->getBalance() << std::endl;
				std::cout << std::endl;
				break;
		}
		input = -1;
	}
}

//list product for sale
void Seller::postProduct(std::vector<Product*> *all_p) {
	Product *prod;

	int cat_input = -1;
	//get valid input
	while (cat_input < 0 || cat_input > 5) {
		std::cout << "What would you like to sell?" << std::endl;
		std::cout << "Enter 1 for Technology" << std::endl;
		std::cout << "Enter 2 for Furniture" << std::endl;
		std::cout << "Enter 3 for Clothing" << std::endl;
		std::cout << "Enter 4 for Toy" << std::endl;
		std::cout << "Enter 5 for Health" << std::endl;
		std::cout << "Enter 0 to cancel" << std::endl;
		std::cin >> cat_input;
	}

	std::string d;
	float p;
	Quality q;

	std::cout << "Enter a description: ";
	std::cin.ignore();
	std::getline(std::cin, d);
	std::cout << "Enter a price: ";
	std::cin >> p;

	int qual_input = -1;
	//get valid input
	while (qual_input < 1 || qual_input > 4) {
		std::cout << "Quality" << std::endl;
		std::cout << "Enter 1 for New" << std::endl;
		std::cout << "Enter 2 for VeryGood" << std::endl;
		std::cout << "Enter 3 for Good" << std::endl;
		std::cout << "Enter 4 for Okay" << std::endl;
		std::cin >> qual_input;
	}
	switch (qual_input) {
		case 1:
			q = Quality::New;
			break;
		case 2:
			q = Quality::VeryGood;
			break;
		case 3:
			q = Quality::Good;
			break;
		case 4:
			q = Quality::Okay;
			break;
	}

	switch (cat_input) {
		case 0:
			return;
		case 1:
			prod = new Technology(d, p, q, this);
			break;
		case 2:
			prod = new Furniture(d, p, q, this);
			break;
		case 3:
			prod = new Clothing(d, p, q, this);
			break;
		case 4:
			prod = new Toy(d, p, q, this);
			break;
		case 5:
			prod = new Health(d, p, q, this);
			break;
	}

	this->products.push_back(prod);
	all_p->push_back(prod);
}

//end bidding on a product and complete the transaction
void Seller::closeBid(std::vector<Product*> *all_p) {
	if (products.size() == 0) {
		std::cout << "You have no products" << std::endl;
		return;
	}

	int num = 1;
	int index = 0;
	int input;
	std::vector<int> indices;

	//list buyers products for sale
	std::cout << "Which of your products would you like to close bidding on?" << std::endl;
	for (Product *p : products) {
		if (!p->isSold()) {
			std::cout << num << ": ";
			p->printProduct();
			indices.push_back(index);
			num += 1;
		}
		index++;
	}
	std::cout << "Enter 1 - " << products.size() << ':' << std::endl;
	std::cin >> input;
	Product *p = products[indices[input-1]];
	p->setSold();
	if (p->hasBids()) {
		Bid *bid = p->getHighBid();
		Buyer *buyer = bid->getBuyer();
		buyer->setBalance(bid->getOffer());
		this->setBalance(bid->getOffer());
	}
}

Buyer::Buyer(std::string f, std::string l, std::string ad, int phone) {
	setfName(f);
	setlName(l);
	setAddress(ad);
	setNumber(phone);
}

//get interaction from user
void Buyer::getInteraction(std::vector<Product*> all_p) {
	int input = -1;

	while (input < 0 || input > 4) {
		std::cout << "Enter 1 to bid on a product" << std::endl;
		std::cout << "Enter 2 to check bids on a product" << std::endl;
		std::cout << "Enter 3 to view similar products" << std::endl;
		std::cout << "Enter 4 to view all products" << std::endl;
		std::cout << "Enter 5 to update account information" << std::endl;
		std::cout << "Enter 6 to check balance" << std::endl;
		std::cout << "Enter 0 to quit" << std::endl;
		std::cin >> input;
		std::cout << std::endl;

		switch (input) {
			case 0:
				return;
			case 1:
				this->placeBid(all_p);
				std::cout << std::endl;
				break;
			case 2:
				this->checkBids();
				std::cout << std::endl;
				break;
			case 3:
				this->viewSimilar(all_p);
				std::cout << std::endl;
				break;
			case 4:
				this->viewProducts(all_p);
				std::cout << std::endl;
				break;
			case 5:
				this->updateInfo();
				std::cout << std::endl;
				break;
			case 6:
				std::cout << "Balance: " << this->getBalance() << std::endl;
				std::cout << std::endl;
				break;
		}
		input = -1;
	}
}

//view buyers open bids
void Buyer::checkBids() {
	if (biddedOn.empty()) {
		std::cout << "You don't have any open bids" << std::endl;
		return;
	}

	///list open bids
	int num = 1;
	for (Product *p : biddedOn) {
		std::cout << num << ": ";
		p->printProduct();
		std::cout << "Your bid: $";
		float high = 0;
		for (Bid *b : p->bids) {
			if (this == b->getBuyer()) {
				if (b->getOffer() > high) {
					high = b->getOffer();
				}
			}
		}
		num += 1;
		std::cout << high << std::endl;
	}
}

//place a bid on a product
void Buyer::placeBid(std::vector<Product*> all_p) {
	std::vector<int> indices;
	int num = 1;
	int index = 0;
	int input;

	//list available products for bidding
	std::cout << "Which product would you like to bid on?" << std::endl;
	for (Product *p : all_p) {
		if (!p->isSold()) {
			std::cout << num << ": ";
			p->printProduct();
			indices.push_back(index);
			num += 1;
		}
		index++;
	}

	std::cin >> input;
	Product *p = all_p[indices[input-1]];
	if (p->getHighOffer() > this->getBalance()) {
		std::cout << "You do not have enough to bid on that product" << std::endl;
		return;
	}

	float bidOffer = 0;
	//get valid bid
	while (bidOffer < p->getHighOffer() || bidOffer > this->getBalance()) {
		std::cout << "What is your offer? (" << p->getHighOffer() << " - " << this->getBalance() << ')' << std::endl;
		std::cin >> bidOffer;
	}
	Bid *b = new Bid(bidOffer, this);
	p->bids.push_back(b);
	biddedOn.push_back(p);
}