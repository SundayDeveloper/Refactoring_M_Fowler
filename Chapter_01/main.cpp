#include "Customer.hpp"
#include <iostream>

int main()
{
  Customer customer("Armageddon");

  std::cout << customer.statement();
  std::cout.flush();

  
  return 0;
}