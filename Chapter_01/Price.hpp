#pragma once

class Price {
  
  public:
    enum Code { REGULAR, NEW_RELEASE, CHILDRENS };
    virtual Code getPriceCode() const = 0;
};

class RegularPrice : public Price {
  public:
    Code getPriceCode() const { return REGULAR; }

};

class NreReleasePrice : public Price {
  public:
    Code getPriceCode() const { return NEW_RELEASE; }

};

class ChildrensPrice : public Price {
  public:
    Code getPriceCode() const { return CHILDRENS; }
};