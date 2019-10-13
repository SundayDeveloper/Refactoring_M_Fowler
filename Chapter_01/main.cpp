#include "Customer.hpp"
#include <iostream>

int main()
{
  Customer customer("Armageddon");

  Movie movie1("The day after", Movie::NEW_RELEASE);
  Rental rental1(movie1, 5);
  customer.addRental(rental1);

  Movie movie2("Nichijo", Movie::CHILDREN);
  Rental rental2(movie2, 3);
  customer.addRental(rental2);


  std::cout << customer.statement();
  std::cout.flush();

  
  return 0;
}