#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Yesterday {
public:
  void SetWeather(string yesterdayWeather);
  void SetHumidity(double yesterdayHumidity);
  string GetWeather() const;
  double GetHumidity() const;

private:
  string weather;
  double humidity;
};

void Yesterday::SetWeather(string yesterdayWeather) {
  weather = yesterdayWeather;
}

void Yesterday::SetHumidity(double yesterdayHumidity) {
  humidity = yesterdayHumidity;
}

/* Your code goes here */
string Yesterday::GetWeather() const { return weather; }
double Yesterday::GetHumidity() const { return humidity; }

int main() {
  Yesterday weather;
  string inputWeather;
  double inputHumidity;

  cin >> inputWeather;
  cin >> inputHumidity;
  weather.SetWeather(inputWeather);
  weather.SetHumidity(inputHumidity);

  cout << "Yesterday: " << weather.GetWeather() << endl;
  cout << "Humidity: " << fixed << setprecision(1) << weather.GetHumidity()
       << "%" << endl;

  return 0;
}
