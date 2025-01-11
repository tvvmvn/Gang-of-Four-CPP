#include <vector>
using namespace std;

// Interface: Strategy
class SortingStrategy {
  public:
    virtual void sort(vector<int>& arr) = 0;
};

// Concrete Strategy
class BubbleSort : public SortingStrategy {
  public:
    void sort(vector<int>& arr) override {
      // Implement Bubble Sort algorithm
    }
};

// Concrete Strategy
class QuickSort : public SortingStrategy {
  public:
    void sort(vector<int>& arr) override {
      // Implement Quick Sort algorithm
    }
};
 
// Context
class SortContext {
  private:
    SortingStrategy* strategy;
  
  public:
    void setStrategy(SortingStrategy* strategy) {
      this->strategy = strategy;
    }
  
    void executeStrategy(vector<int>& arr) {
      strategy->sort(arr);
    }
};

// Client
int main() {
  // Strategies
  SortContext context;
  BubbleSort bubbleSort;
  QuickSort quickSort;

  vector<int> data = { 5, 2, 7, 1, 9 };
 
  // Set strategy and executes algorithm.
  context.setStrategy(&bubbleSort);
  context.executeStrategy(data);
 
  // Set strategy and executes algorithm.
  context.setStrategy(&quickSort);
  context.executeStrategy(data); 
 
  return 0;
}