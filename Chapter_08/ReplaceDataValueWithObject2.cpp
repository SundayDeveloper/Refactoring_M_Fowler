#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

using std::string;
using std::vector;

using std::cout;
using std::endl;

class Customer {
private:
  string name;
public:
  Customer() {}
  Customer(const string &name_) { name = name_; }
  const string& Get_Name() const { return name; }
};

class Order {
private:
  Customer customer;
public:
  Order() {}
  Order(const string &customer_) { customer = Customer(customer_); }
  string Get_Customer() const { return customer.Get_Name(); }
  void Set_Customer(const string &customer_) { cu stomer = Customer(customer_); }
};

int Get_NumberOfOrdersFor(const vector<Order> &orders, const string &customer)
{
  auto result = 0;
  for(auto &ord : orders){
    if(!ord.Get_Customer().compare(customer)){
      ++result;
    }
  }
  return result;
}

int main()
{
  std::vector<Order> orders(3);
  auto i = 0;
  orders[i++].Set_Customer("a");
  orders[i++].Set_Customer("b");
  orders[i++].Set_Customer("a");

  cout << Get_NumberOfOrdersFor(orders, "a") << endl;
  cout << Get_NumberOfOrdersFor(orders, "b") << endl;

  return 0;
}