#include "Customer.hpp"
#include <iostream>

int main()
{
  Customer customer("Armageddon");

  Movie movie("The day after", Movie::NEW_RELEASE);
  Rental rental(movie, 5);
  customer.addRental(rental);

  std::cout << customer.statement();
  std::cout.flush();

  
  return 0;
}