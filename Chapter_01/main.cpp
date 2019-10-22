#include "Customer.hpp"
#include "Price.hpp"

#include <iostream>

int main()
{
  Customer customer("Armageddon");

  Movie movie1("The day after", Price::Code::NEW_RELEASE);
  Rental rental1(movie1, 5);
  customer.addRental(rental1);

  Movie movie2("Nichijo", Price::Code::CHILDRENS);
  Rental rental2(movie2, 3);
  customer.addRental(rental2);

  std::cout << customer.HtmlStatements();
  std::cout.flush();

  
  return 0;
}