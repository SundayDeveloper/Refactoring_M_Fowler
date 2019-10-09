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

};