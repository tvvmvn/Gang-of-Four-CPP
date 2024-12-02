#include <iostream>
using namespace std;

// State Interface
class TrafficLightState {
  public:
    virtual void handle() = 0;
};

// Concrete States
class RedState : public TrafficLightState {
  public:
    void handle() override {
      cout << "Sending Red" << endl;
    }
};

class YellowState : public TrafficLightState {
  public:
    void handle() override {
      cout << "Sending Yellow" << endl;
    }
};

class GreenState : public TrafficLightState {
  public:
    void handle() override {
      cout << "Sending Green" << endl;
    }
};

// Context
class TrafficLight {
  private:
    // States
    TrafficLightState* state;

  public:
    void setState(TrafficLightState* newState) {
      state = newState;
    };

    void request() { 
      state->handle();
    }
};

int main() {
  // States
  TrafficLightState* red = new RedState();
  TrafficLightState* green = new GreenState();
  TrafficLightState* yellow = new YellowState();

  // Context
  TrafficLight trafficLight;

  // Set state (like user input) and handling requests
  trafficLight.setState(yellow);
  trafficLight.request();
  trafficLight.setState(red);
  trafficLight.request();
  trafficLight.setState(green);
  trafficLight.request();

  return 0;
}

/*
Output 

Sending Yellow
Sending Red
Sending Green
*/