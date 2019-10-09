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
  Movie(std::string &title, const int priceCode){
    _title = title;
    _priceCode = priceCode;
  }

public:
  inline int getPriceCode() { return _priceCode; }
  inline void setPriceCode(const int arg) { _priceCode = arg; }

  std::string getTitle() { return _title; }

};