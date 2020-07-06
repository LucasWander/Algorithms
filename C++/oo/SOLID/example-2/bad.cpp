#include <iostream>
#include <exception>


class UnsupportedMethod: public std::exception {
  virtual const char* what() const throw()
  {
    return "Unsupported method";
  }
} Unsupported;


class Bird {

protected:
  double latitude;
  double longitude;
  double altitude;


public:
  virtual void setLocalization(double latitude, double longitude) = 0;

  virtual void setAltitude(double altitude) = 0;

  virtual double getLatitude() = 0;

  virtual double getLongitude() = 0;

  virtual void render() = 0;
};

class Eagle: public Bird {

public:
  void setLocalization(double latitude, double longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
  }

  double getLatitude() {
    return this->latitude;
  }

  void setAltitude(double altitude) {
    this->altitude = altitude;
  }

  double getLongitude() {
    return this->longitude;
  }

  void render() {
    std::cout << "Render: " << this->latitude << " " << this->longitude << " " << this->altitude << std::endl;
  }
};


class Penguin: public Bird {

public:
  void setLocalization(double latitude, double longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
  }

  double getLatitude() {
    return this->latitude;
  }

  void setAltitude(double altitude) {
    throw Unsupported;
  }

  double getLongitude() {
    return this->longitude;    
  }

  void render() {
    std::cout << "Render: " << this->latitude << " " << this->longitude << std::endl;
  }
};

int main() {

  Bird *bird = new Eagle();
  Penguin *pinguim = new Penguin();


  pinguim->setLocalization(45, 12);
  pinguim->render();
  try {
    pinguim->setAltitude(12);
  }
  catch(std::exception & e) {
    std::cout << e.what() << std::endl;
  }


  bird->setLocalization(1.1, 20.5);
  bird->setAltitude(45);
  bird->render();

}