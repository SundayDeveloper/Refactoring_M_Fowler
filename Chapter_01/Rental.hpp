#pragma once

#include "Movie.hpp"

class Rental {

private:
  Movie _movie;
  int _daysRented;

public:

  Rental() {};
  Rental (const Movie &movie, const int daysRented) :
   _movie(movie), _daysRented(daysRented) { }

  inline int getDaysRented() const { return _daysRented; }

  inline Movie getMovie() const { return _movie; }

  double getCharge() const
  {
    auto thisAmount = 0.0;
    switch(getMovie().getPriceCode() ) {
        
      case Movie::REGULAR :
        thisAmount += 2.0;
        if( getDaysRented() > 2){
            thisAmount += (getDaysRented() - 2 ) * 1.5;
          }
          break;

        case Movie::NEW_RELEASE :
          thisAmount += getDaysRented() * 3.0;
          break;

        case Movie::CHILDREN:
          thisAmount += 1.5;
          if( getDaysRented() > 3){
            thisAmount += ( getDaysRented() - 3 ) * 1.5;
          }
          break;
      }

    return thisAmount;

  }

  int getFrequentRenterPoints() const
  {
      auto frequentRenterPoints = 1;

      if( (getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
           getDaysRented() > 1 )
      {
        frequentRenterPoints++; 
      }

      return frequentRenterPoints;

  }
};

