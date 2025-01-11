#include <iostream>
#include <string>
using namespace std;

// fat interface
class MFP {
  public:
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};

// Break down the MFP interface into smaller interfaces.
class Printer {
  public:
    virtual void print() = 0;
};

class Scanner {
  public:
    virtual void scan() = 0;
};

class Fax {
  public:
    virtual void fax() = 0;
};