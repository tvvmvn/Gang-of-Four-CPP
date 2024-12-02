#include <iostream>
#include <string>
using namespace std;

// Adaptee
class LegacyPrinter {
  public:
    void print(const string& command) {
      cout << "Command through adapter: " << command << endl;
    }
};

// Adapter Interface
class Adapter {
  public:
    virtual void print(const string& command) = 0;
};

// Concrete Adapter 
class PrinterAdapter : public Adapter {
  private:
    LegacyPrinter legacyPrinter;

  public:
    void print(const string& command) {
      // Convert the command to uppercase and pass it to the LegacyPrinter
      string uppercaseCommand = command;

      for (char& c : uppercaseCommand) {
        c = toupper(c);
      }

      legacyPrinter.print(uppercaseCommand);
    }
};

// Client
int main() {
  Adapter* printAdapter = new PrinterAdapter();

  // Command adapter to print 
  printAdapter->print("Print this");

  return 0;
}

/*
Output

Command through adapter: PRINT THIS
*/