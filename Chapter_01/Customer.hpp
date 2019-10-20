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

  double getTotalCharge() const  {

    auto result  = 0.0;
    for( const auto &rental : _rentals){
      result += rental.getCharge();
    }

    return result;
  }

  int getTotalFrequentRenterPoints()
  {
    auto result = 0;
    
    for( const auto &rental : _rentals){
      result += rental.getFrequentRenterPoints();      
    }

    return result;
  }

  std::string statement()
  {
        
    std::string result = "Rental Record for " + getName() + '\n';

    for( const auto &rental : _rentals){
      result += "\t" + rental.getMovie().getTitle() +
                "\t" + std::to_string(rental.getCharge() )  + 
                "(" + std::to_string( rental.getDaysRented() ) + " days)" + 
                "\n";
      
    }

    result += "Amount owed is " + std::to_string( getTotalCharge() ) + "\n";
    result += "You earned "     + std::to_string( getTotalFrequentRenterPoints() ) +
              " frequent renter porints";

    return result;

  }

  std::string HtmlStatements()
  {
    std::string result = "<H1>Rentals for <EM>" + getName() + "</EM></H1><P>\n";
    for(const auto &rental : _rentals){
      result += rental.getMovie().getTitle() + ": " +
                std::to_string(rental.getCharge())  + 
                "(" + std::to_string( rental.getDaysRented() ) + " days)" + 
                "<BR>\n";

    }
    
    return result;
  }


};