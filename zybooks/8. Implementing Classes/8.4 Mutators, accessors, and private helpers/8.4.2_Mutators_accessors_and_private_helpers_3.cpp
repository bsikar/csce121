#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Yesterday {
public:
  void SetWeather(string yesterdayWeather);
  void SetTemperature(double yesterdayTemperature);
  string GetWeather() const;
  double GetTemperature() const;
  void Print() const;

private:
  string weather;
  double temperature;
};

void Yesterday::SetWeather(string yesterdayWeather) {
  weather = yesterdayWeather;
}

void Yesterday::SetTemperature(double yesterdayTemperature) {
  temperature = yesterdayTemperature;
}

string Yesterday::GetWeather() const { return weather; }

double Yesterday::GetTemperature() const { return temperature; }

int main() {
  Yesterday weather;
  string inputWeather;
  double inputTemperature;

  cin >> inputWeather;
  cin >> inputTemperature;

  /* Your code goes here */
  weather.SetTemperature(inputTemperature);
  weather.SetWeather(inputWeather);

  cout << "Today's weather is " << weather.GetWeather();
  cout << " and the temperature is " << fixed << setprecision(1)
       << weather.GetTemperature() << " degrees Fahrenheit" << endl;

  return 0;
}
