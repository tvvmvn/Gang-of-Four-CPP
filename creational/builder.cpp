#include <iostream>
#include <string>
using namespace std;

// Product class
class Pizza {
  private:
    string dough;
    string sauce;
    string topping;

  public:
    void setDough(const string& dough) {
      this->dough = dough;
    }

    void setSauce(const string& sauce) {
      this->sauce = sauce;
    }

    void setTopping(const string& topping) {
      this->topping = topping;
    }

    void display() const {
      cout << "Dough: " << dough << ", Sauce: " << sauce << ", Topping: " << topping << endl;
    }
};

// Abstract builder class
class PizzaBuilder {
  public:
    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() const = 0;
};

// Concrete builder for a specific type of pizza
class HawaiianPizzaBuilder : public PizzaBuilder {
  private:
    Pizza pizza;

  public:
    void buildDough() override {
      pizza.setDough("Pan Dough");
    }

    void buildSauce() override {
      pizza.setSauce("Hawaiian Sauce");
    }

    void buildTopping() override {
      pizza.setTopping("Ham and Pineapple");
    }

    Pizza getPizza() const override { 
      return pizza; 
    }
};

// Concrete builder for another type of pizza
class SpicyPizzaBuilder : public PizzaBuilder {
  private:
    Pizza pizza;

  public:
    void buildDough() override {
      pizza.setDough("Thin Dough");
    }

    void buildSauce() override {
      pizza.setSauce("Spicy Tomato Sauce");
    }

    void buildTopping() override {
      pizza.setTopping("Pepperoni and Jalapenos");
    }

    Pizza getPizza() const override { 
      return pizza; 
    }
};

// Director class that orchestrates the construction
class Cook {
  private:
    PizzaBuilder* hawaiianBuilder = new HawaiianPizzaBuilder();
    PizzaBuilder* spicyBuilder = new SpicyPizzaBuilder();

  public:
    Pizza makeHawaiianPizza() {
      hawaiianBuilder->buildDough();
      hawaiianBuilder->buildSauce();
      hawaiianBuilder->buildTopping();

      return hawaiianBuilder->getPizza();
    }

    Pizza makeSpicyPizza() {
      spicyBuilder->buildDough();
      spicyBuilder->buildSauce();
      spicyBuilder->buildTopping();
      
      return spicyBuilder->getPizza();
    }
};

int main() {
  // Director
  Cook cook;

  // Products
  Pizza hawaiianPizza = cook.makeHawaiianPizza();
  Pizza spicyPizza = cook.makeSpicyPizza();

  hawaiianPizza.display();
  spicyPizza.display();

  return 0;
}

/*
Output

Dough: Pan Dough, 
Sauce: Hawaiian Sauce, 
Topping: Ham and Pineapple

Dough: Thin Dough, 
Sauce: Spicy Tomato Sauce, 
Topping: Pepperoni and Jalapenos
*/