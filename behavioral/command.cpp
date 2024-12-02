#include <iostream>
#include <vector>
using namespace std;

// Receiver
class TV {
  public:
    void powerOn() {
      cout <<" is ON now" << endl;
    }

    void powerOff() {
      cout << " is OFF now" << endl;
    }
};

// Command interface
class Command {
  public:
    virtual void execute() = 0;
};

// Concrete Command
class TurnOnTV : public Command {
  private:
    TV tv;

  public:
    void execute() { 
      tv.powerOn(); 
    }
};

// Concrete Command
class TurnOffTV : public Command {
  private:
    TV tv;

  public:
    void execute() { 
      tv.powerOff(); 
    }
};

// Invoker
class RemoteControl {
  Command* command;

  public:
    void setCommand(Command* command) {
      this->command = command;
    }

    void pressButton() {
      command->execute();
    }
};

int main() {
  // Set commands on TV
  Command* turnOnTV = new TurnOnTV();
  Command* turnOffTV = new TurnOffTV();
  
  // Create a remote control
  RemoteControl remote;

  // Set and execute commands.
  remote.setCommand(turnOnTV);
  remote.pressButton();
  remote.setCommand(turnOffTV);
  remote.pressButton();

  return 0;
}

/*
Output

TV is now ON.
TV is now OFF.
*/