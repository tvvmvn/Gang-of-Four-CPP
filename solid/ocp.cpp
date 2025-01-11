#include <iostream>
#include <string>
using namespace std;


class PaymentProcessor {
  public:
    void withCreditCard() {}
};

// you better extends a class, without modifying a class.
// then you can go back to previous one at anytime.
class PaymentProcessorExtended : PaymentProcessor {
  public:
    void withApplePay() {}
};
