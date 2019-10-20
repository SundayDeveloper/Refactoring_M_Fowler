#pragma once

#include <string>

class Movie {
  
public:
  static const int CHILDREN = 2;
  static const int REGULAR = 0;
  static const int NEW_RELEASE = 1;

private:
  std::string _title;
  int _priceCode;

public:
  Movie() {};

  Movie(std::string title, const int priceCode){
    _title = title;
    _priceCode = priceCode;
  }

  inline int getPriceCode() const  { return _priceCode; };
  inline void setPriceCode(const int arg) { _priceCode = arg; } 

  std::string getTitle() const { return _title; }

  double getCharge(const int daysRented) const
  {
    auto thisAmount = 0.0;
    switch( getPriceCode() ) {
        
      case Movie::REGULAR :
        thisAmount += 2.0;
        if( daysRented > 2){
            thisAmount += ( daysRented - 2 ) * 1.5;
          }
          break;

        case Movie::NEW_RELEASE :
          thisAmount += daysRented * 3.0;
          break;

        case Movie::CHILDREN:
          thisAmount += 1.5;
          if( daysRented > 3){
            thisAmount += ( daysRented - 3 ) * 1.5;
          }
          break;
      }

    return thisAmount;

  }


};