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

      auto thisAmount = amountFor(rental);
      frequentRenterPoints++;

      if( (rental.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
           rental.getDaysRented() > 1 ) { frequentRenterPoints++; }
          
      result += "\t" + rental.getMovie().getTitle() + "\t" +
                std::to_string(thisAmount)  + "\n";
      totalAmount += thisAmount;
    }

    result += "Amount owed is " + std::to_string(totalAmount) + "\n";
    result += "You earned " + std::to_string(frequentRenterPoints) +
              " frequent renter porints";

    return result;

  }

private:
  double amountFor(const Rental &aRental)
  {
    auto thisAmount = 0.0;
    switch(aRental.getMovie().getPriceCode() ) {
        
      case Movie::REGULAR :
        thisAmount += 2.0;
        if( aRental.getDaysRented() > 2){
            thisAmount += (aRental.getDaysRented() - 2 ) * 1.5;
          }
          break;

        case Movie::NEW_RELEASE :
          thisAmount += aRental.getDaysRented() * 3.0;
          break;

        case Movie::CHILDREN:
          thisAmount += 1.5;
          if( aRental.getDaysRented() > 3){
            thisAmount += (aRental.getDaysRented() - 3 ) * 1.5;
          }
          break;
      }

    return thisAmount;

  }
};