#include <string>
#include <vector>
#include <iostream>

class Bid;
class Product;

class User {
	public:
		User();
		//virtual ~User() { }
		void setfName(std::string fname);
		void setlName(std::string lname);
		void setAddress(std::string address);
		void setNumber(int n);
		void setBalance(float n);
		std::string getfName();
		std::string getlName();
		std::string getAddress();
		int getNumber();
		float getBalance();
		void viewProducts(std::vector<Product*> all_p);
		void viewSimilar(std::vector<Product*> all_p);
		virtual void getInteraction(std::vector<Product*> all_p) = 0;
		void updateInfo();

	private:
		std::string firstName;
		std::string lastName;
		std::string address;
		int phoneNumber;
		float balance;
		float rating;
		int numOfRatings;
};

class Seller : public User {
	public:
		Seller(std::string first, std::string last, std::string address, int phoneNumber);
		void getInteraction(std::vector<Product*> all_p);
		void postProduct(std::vector<Product*> *all_p);
		void closeBid(std::vector<Product*> *all_p);

	private:
		std::vector<Product*> products;
};

class Buyer : public User {
	public:
		Buyer(std::string first, std::string last, std::string address, int phoneNumber);
		void getInteraction(std::vector<Product*> all_p);
		void placeBid(std::vector<Product*> all_p);
		void checkBids();

	private:
		std::vector<Product*> biddedOn;
};