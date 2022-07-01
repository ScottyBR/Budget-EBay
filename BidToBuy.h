#include <fstream>
#include <sstream>
#include "User.h"
#include "Sale.h"

class BidToBuy {
	public:
		BidToBuy();
		void initData();
		void Run();
		std::vector<User*> getUsers() { return users; }
		User* createUser();
		std::vector<Product*> getProducts();

	private:
		std::vector<User*> users;
		std::vector<Product*> products;
		std::vector<Seller*> sellers;
		std::vector<Buyer*> buyers;
};