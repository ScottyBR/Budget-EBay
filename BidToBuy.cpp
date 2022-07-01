#include "BidToBuy.h"


//initialize test data
BidToBuy::BidToBuy() {
	initData();
}

//run BtB
void BidToBuy::Run() {
	int input = -1;
	User *u;

	//while user wants to continue
	while (input != 0) {
		//if there are no users make one
		if (users.size() == 0) {
			u = createUser();
		}
		//there are users already
		//check if existing user or new user
		else {
			//get valid input
			while (input < 0 || input > 2) {
				std::cout << "Enter 1 for new user" << std::endl;
				std::cout << "Enter 2 for existing user" << std::endl;
				std::cout << "Enter 0 to quit" << std::endl;
				std::cin >> input;
				std::cout << std::endl;
			}
			//exit
			if (input == 0) {
				break;
			}
			//new user
			else if (input == 1) {
				u = createUser();
			}
			//existing user
			else {
				int i = 1;

				std::cout << "Available users:" << std::endl;
				for (User *u : users) {
					std::cout << i << ': ' << u->getfName() << ' ' << u->getlName() << std::endl;
					i++;
				}

				int user_input = 0;
				
				while (user_input < 1 || user_input > users.size()) {
					std::cout << "Which user are you 1 - " << users.size() << "?: ";
					std::cin >> user_input;
					std::cout << std::endl;
				}
				u = users[user_input - 1];
			}
		}
		u->getInteraction(products);

		input = -1;
	}
}

//create new user
User* BidToBuy::createUser() {
	std::string input;
	User *u;

	while (input != "seller" && input != "buyer") {
		std::cout << "Would you like to be a buyer or seller" << std::endl;
		std::cout << "Enter 'buyer' or 'seller': ";
		std::cin >> input; 
	}

	std::string first, last, address;
	int number;
	std::cout << "Enter first name: ";
	std::cin >> first;
	std::cout << "Enter last name: ";
	std::cin >> last;
	std::cout << "Enter address: ";
	std::cin >> address;
	std::cout << "Enter phone number: ";
	std::cin >> number;

	if (input == "seller") {
		u = new Seller(first, last, address, number);
	}
	else {
		u = new Buyer(first, last, address, number);
	}
	std::cout << std::endl;

	users.push_back(u);

	return u;
}

//initialize test data
void BidToBuy::initData() {
	std::string user_line;
	std::ifstream user_file("user_init.csv");

	while (std::getline(user_file, user_line)) {
		std::vector<std::string> user_vec;
		std::stringstream user_ss(user_line);

		while(std::getline(user_ss, user_line, ',')) {
    		user_vec.push_back(user_line);
    	}

    	if (user_vec[0] == "buyer") {
    		buyers.push_back(new Buyer(user_vec[1], user_vec[2], user_vec[3], std::stol(user_vec[4])));
    	}
    	else {
    		sellers.push_back(new Seller(user_vec[1], user_vec[2], user_vec[3], std::stol(user_vec[4])));
    	}
    }

    std::string bids_line;
	std::ifstream bids_file("bids_init.csv");
	std::vector <Product*> temp_products;

	while (std::getline(bids_file, bids_line)) {
		std::vector<std::string> bids_vec;
		std::stringstream bids_ss(bids_line);

		while(std::getline(bids_ss, bids_line, ',')) {
    		bids_vec.push_back(bids_line);
    	}
    	std::string type = bids_vec[0];
    	std::string description = bids_vec[1];
    	float price = std::stof(bids_vec[2]);
    	Quality condition;
    	if (bids_vec[3] == "new") {
    		condition = Quality::New;
    	}
    	else if (bids_vec[3] == "verygood") {
    		condition = Quality::VeryGood;
    	}
    	else if (bids_vec[3] == "good") {
    		condition = Quality::Good;
    	}
    	else if (bids_vec[3] == "okay") {
    		condition = Quality::Okay;
    	}

    	if (type == "technology") {
    		temp_products.push_back(new Technology(description, price, condition, sellers[0]));
    	}
    	else if (type == "furniture") {
    		temp_products.push_back(new Furniture(description, price, condition, sellers[0]));
    	}
    	else if (type == "clothing") {
    		temp_products.push_back(new Clothing(description, price, condition, sellers[0]));
    	}
    	else if (type == "toy") {
    		temp_products.push_back(new Toy(description, price, condition, sellers[0]));
    	}
    	else if (type == "health") {
    		temp_products.push_back(new Health(description, price, condition, sellers[0]));
    	}
    }
    products = temp_products;
}

std::vector<Product*> BidToBuy::getProducts() {
	return products;
}