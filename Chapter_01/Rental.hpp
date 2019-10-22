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
    return _movie.getCharge(_daysRented);
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
