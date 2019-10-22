#pragma once

#include <string>
#include "Price.hpp"

class Movie {
  
public:
  //static const int CHILDRENS = 2;
  //static const int REGULAR = 0;
  //static const int NEW_RELEASE = 1;

private:
  std::string _title;
  //int _priceCode;
  Price::Code _priceCode;

public:
  Movie() {};

  Movie(std::string title, const Price::Code priceCode){
    setTitle(title);
    setPriceCode(priceCode);
  }

  inline Price::Code getPriceCode() const  { return _priceCode; };
  inline void setPriceCode(const Price::Code arg) { _priceCode = arg; } 

  inline void setTitle(const std::string title) { _title = title; }
  inline std::string getTitle() const { return _title; }

  double getCharge(const int daysRented) const
  {
    auto thisAmount = 0.0;
    switch( getPriceCode() ) {
        
      case Price::Code::REGULAR :
        thisAmount += 2.0;
        if( daysRented > 2){
            thisAmount += ( daysRented - 2 ) * 1.5;
          }
          break;

        case Price::Code::NEW_RELEASE :
          thisAmount += daysRented * 3.0;
          break;

        case Price::Code::CHILDRENS:
          thisAmount += 1.5;
          if( daysRented > 3){
            thisAmount += ( daysRented - 3 ) * 1.5;
          }
          break;
      }

    return thisAmount;

  }

  int getFrequentRenterPoints(const int daysRented) const
  {
      auto frequentRenterPoints = 1;
  
      if( (getPriceCode() == Price::Code::NEW_RELEASE) &&
           daysRented > 1 )
      {
        frequentRenterPoints++; 
      }

      return frequentRenterPoints;
  }


};