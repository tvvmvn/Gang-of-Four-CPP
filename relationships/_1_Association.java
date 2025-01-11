package oop.relationships;

class Address {
  
  public String city;
  public String street;

  public Address(String city, String street) {
    this.city = city;
    this.street = street;
  }

  public String toString() {
    return String.format("Address[city='%s', street='%s']", city, street);
  }
};

class Person {
  
  public String name;
  public Address address;

  public Person(String name, Address address) {
    this.name = name;
    this.address = address;
  }
};

class _1_Association {
  public static void main(String[] args) {

    Address address = new Address("Seoul", "st");

    Person john = new Person("John", address);

    System.out.println(john.address);
  }
}

// Output
// Address[city='Seoul', street='st']