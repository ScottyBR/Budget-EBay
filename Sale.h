#include <string>
#include <vector>

class Buyer;
class Seller;

enum class Quality {New, VeryGood, Good, Okay};

struct Bid {
	Bid(float offer, Buyer *b);
	float getOffer();
	Buyer* getBuyer();

	float offer;
	Buyer *buyer;
};

struct Product {
	std::string getDescription();
	float getPrice();
	std::string printQuality();
	bool isSold();
	Bid* getHighBid();
	float getHighOffer();
	void printProduct();
	void setSold();
	bool hasBids();
	virtual std::string stringType() = 0;

	float price;
	std::string description;
	Quality condition;
	Seller *seller;
	bool sold;
	std::vector<Bid*> bids;
};

struct Technology : public Product {
	Technology(std::string d, float p, Quality c, Seller *s);
	std::string stringType();
};

struct Furniture : public Product {
	Furniture(std::string d, float p, Quality c, Seller *s);
	std::string stringType();
};

struct Clothing : public Product {
	Clothing(std::string d, float p, Quality c, Seller *s);
	std::string stringType();
};

struct Toy : public Product {
	Toy(std::string d, float p, Quality c, Seller *s);
	std::string stringType();
};

struct Health : public Product {
	Health(std::string d, float p, Quality c, Seller *s);
	std::string stringType();
};