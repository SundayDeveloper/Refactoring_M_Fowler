#pragma once

class Price {
  
public:
  enum class Code { REGULAR, NEW_RELEASE, CHILDRENS };
	virtual Code getPriceCode() const = 0;
	
	Price(){};
	virtual ~Price() = 0;
};

class RegularPrice : public Price {
public:
	RegularPrice(){};
	~RegularPrice(){};
	
	Code getPriceCode() const { return Code::REGULAR; }
	
};

class NewReleasePrice : public Price {
public:
	NewReleasePrice(){};
  ~NewReleasePrice(){};
	Code getPriceCode() const { return Code::NEW_RELEASE; }
	
};

class ChildrensPrice : public Price {
public:
  ChildrensPrice(){};
  ~ChildrensPrice(){};
	Code getPriceCode() const { return Code::CHILDRENS; }
};
