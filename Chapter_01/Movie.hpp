#pragma once

#include <string>
#include "Price.hpp"

class Movie { 
  
protected:
  std::string _title;
  Price::Code _priceCode;
  Price *_price = nullptr;

public:
  Movie() {};

  Movie(std::string title, const Price::Code priceCode){
    setTitle(title);
    setPriceCode(priceCode);
  }

  ~Movie()
  {
    if(_price != nullptr){ delete _price;}
  }

protected:
  void setPriceCode(const Price::Code arg)  
  {
    switch (arg) {
      case Price::Code::REGULAR :
        /* code */
        break;
    
      default:
        break;
    }
  }

public:
  inline std::string getTitle() const { return _title; }

protected:
  inline void setTitle(const std::string title){ _title = title; }
public:
  Price::Code getPriceCode() const  { return _price->getPriceCode(); };

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