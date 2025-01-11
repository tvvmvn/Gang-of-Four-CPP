#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Observer interface
class Observer {
  public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Concrete Observer
class PhoneDisplay : public Observer {
  public:
    void update(float temperature, float humidity, float pressure) {
      cout << "Phone Display: Temperature: " << temperature << "°C, "
           << "Humidity: " << humidity << "%, "
           << "Pressure: " << pressure << " hPa"
           << endl;
    }
};

// Concrete Observer
class TVDisplay : public Observer {
  public:
    void update(float temperature, float humidity, float pressure) {
      cout << "TV Display: Temperature: " << temperature << "°C, "
           << "Humidity: " << humidity << "%, "
           << "Pressure: " << pressure << " hPa"
           << endl;
    }
};

// Interface: Subject
class Subject {
  public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// Concrete Subject 
class WeatherStation {
  private:
    float temperature;
    float humidity;
    float pressure;
    vector<Observer* > observers;

  public:
    void registerObserver(Observer* observer) {
      observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
      // You can implement the removal logic if needed.
    }

    void notifyObservers() {
      for (Observer* observer : observers) {
        observer->update(temperature, humidity, pressure);
      }
    }

    void setMeasurements(float temp, float hum, float press) {
      temperature = temp;
      humidity = hum;
      pressure = press;

      notifyObservers();
    }
};

int main() {
  WeatherStation weatherStation;
  Observer* phoneDisplay = new PhoneDisplay();
  Observer* tvDisplay = new TVDisplay();

  // Register displays as observers
  weatherStation.registerObserver(phoneDisplay);
  weatherStation.registerObserver(tvDisplay);

  // Simulate weather data updates
  weatherStation.setMeasurements(25.5, 60, 1013.2);
  weatherStation.setMeasurements(24.8, 58, 1014.5);

  return 0;
}

/*
Output

Phone Display: Temperature: 25.5xc2xb0C, Humidity: 60%, Pressure: 1013.2 hPa
TV Display: Temperature: 25.5xc2xb0C, Humidity: 60%, Pressure: 1013.2 hPa
Phone Display: Temperature: 24.8xc2xb0C, Humidity: 58%, Pressure: 1014.5 hPa
TV Display: Temperature: 24.8xc2xb0C, Humidity: 58%, Pressure: 1014.5 hPa
*/