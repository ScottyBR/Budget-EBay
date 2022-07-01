#include <iostream>
#include <iomanip>
#include "Sale.h"
#include "User.h"

Bid::Bid(float o, Buyer *b) {
	offer = o;
	buyer = b;
}

float Bid::getOffer() {
	return offer;
}

Buyer* Bid::getBuyer() {
	return buyer;
}

std::string Product::getDescription() {
	return description;
}
float Product::getPrice() {
	return price;
}

std::string Product::printQuality() {
	if (condition == Quality::New) {
		return "New ";
	}
	else if (condition == Quality::New) {
		return "VeryGood ";
	}
	else if (condition == Quality::New) {
		return "Good ";
	}
	else {
		return "Okay ";
	}
}

bool Product::isSold() {
	return sold;
}

float Product::getHighOffer() {
	if (!bids.empty()) {
		float high = 0;
		for (Bid* b : bids) {
			if (b->getOffer() > high) {
				high = b->getOffer();
			}
		}
		return high;
	}
	else {
		return price;
	}
}

Bid* Product::getHighBid() {
	Bid *high = 0;
	for (Bid* b : bids) {
		if (b->getOffer() > high->getOffer()) {
			high = b;
		}
	}
	return high;
}

bool Product::hasBids() {
	if (this->bids.empty()) {
		return false;
	}
	else {
		return true;
	}
}

void Product::printProduct() {
	std::cout << this->stringType() << ' ';
	std::cout << this->getDescription() << ' ';
	std::cout << this->printQuality();
	std::cout << '$' << std::fixed << std::setprecision(2) << this->getHighOffer() << std::endl;
}

void Product::setSold() {
	this->sold = true;
}

Technology::Technology(std::string d, float p, Quality c, Seller *s) {
	description = d;
	price = p;
	condition = c;
	seller = s;
	sold = false;
}

Furniture::Furniture(std::string d, float p, Quality c, Seller *s) {
	price = p;
	description = d;
	condition = c;
	seller = s;
	sold = false;
}

Clothing::Clothing(std::string d, float p, Quality c, Seller *s) {
	price = p;
	description = d;
	condition = c;
	seller = s;
	sold = false;
}

Toy::Toy(std::string d, float p, Quality c, Seller *s) {
	price = p;
	description = d;
	condition = c;
	seller = s;
	sold = false;
}

Health::Health(std::string d, float p, Quality c, Seller *s) {
	price = p;
	description = d;
	condition = c;
	seller = s;
	sold = false;
}

std::string Technology::stringType() {
	return "Technology";
}

std::string Furniture::stringType() {
	return "Furniture";
}

std::string Clothing::stringType() {
	return "Clothing";
}

std::string Toy::stringType() {
	return "Toy";
}

std::string Health::stringType() {
	return "Health";
}