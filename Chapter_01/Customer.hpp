#pragma once

#include <string>
#include <vector>

#include "Rental.hpp"

class Customer {

private:
  std::string _name;
  std::vector<Rental> _rentals;

public:
  Customer() {};
  Customer(const std::string name){ _name = name; }

  inline void addRental(const Rental &arg) { _rentals.push_back(arg); }
  inline std::string getName() { return _name; }
  
  std::string statement()
  {
    
    auto totalAmount  = 0.0;
    auto frequentRenterPoints = 0;
    
    std::string result = "Rental Record for " + getName() + '\n';

    for( const auto &rental : _rentals){

      frequentRenterPoints = rental.getFrequentRenterPoints();

      result += "\t" + rental.getMovie().getTitle() +
              + "\t" + std::to_string(rental.getCharge())  + 
              "(" + std::to_string( rental.getDaysRented() ) + " days)" + 
              "\n";
      totalAmount += rental.getCharge();
    }

    result += "Amount owed is " + std::to_string(totalAmount) + "\n";
    result += "You earned " + std::to_string(frequentRenterPoints) +
              " frequent renter porints";

    return result;

  }


};