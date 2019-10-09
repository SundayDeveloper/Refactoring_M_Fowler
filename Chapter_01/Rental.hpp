#pragma once

#include "Movie.hpp"

class Rental {

private:
  Movie _movie;
  int _daysRented;

public:

  Rental (const Movie &movie, const int daysRented) :
   _movie(movie), _daysRented(daysRented) { }

  inline int getDaysRented() const { return _daysRented; }

  inline Movie getMovie() const { return _movie; }
};

