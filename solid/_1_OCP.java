package oop.solid;

class PaymentProcessor {
  public void withCreditCard() {}
};

// you better extends a class, without modifying a class.
// then you can go back to previous one at anytime.
class PaymentProcessorExtended extends PaymentProcessor {
  public void withApplePay() {}
};

class _1_OCP {}