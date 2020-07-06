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
  
public:
  virtual void setLocalization(double latitude, double longitude) = 0;

  virtual double getLatitude() = 0;

  virtual double getLongitude() = 0;

  virtual void render() = 0;
};

class FlyingBirds: public Bird {
protected:
  double altitude;
public:
  virtual void setAltitude(double altitude) = 0;
};

class Eagle: public FlyingBirds {

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

  double getLongitude() {
    return this->longitude;    
  }

  void render() {
    std::cout << "Render: " << this->latitude << " " << this->longitude << std::endl;
  }
};

int main() {

  FlyingBirds *bird = new Eagle();
  Penguin *pinguim = new Penguin();


  pinguim->setLocalization(45, 12);
  pinguim->render();


  bird->setLocalization(1.1, 20.5);
  bird->setAltitude(45);
  bird->render();

}