//Strategy Design Pattern: Design a vehicle system which has different types of drive capabilities.

#include <iostream>
using namespace std;

class DriveStrategy
{
    public:
    virtual void drive() = 0;
};

class NormalDriveStrategy : public DriveStrategy
{
    public:
    void drive()
    {
        cout<<"Normal drive strategy"<<endl;
    }
};

class SpecialDriveStrategy : public DriveStrategy
{
    public:
    void drive()
    {
        cout<<"Special drive strategy"<<endl;
    }
};

class Vehicle
{
    DriveStrategy *driv;
    public:
    Vehicle (DriveStrategy *driv)
    {
        this->driv = driv;
    }
    
    void driveVehicle ()
    {
        driv->drive();
    }
};

class SportsVehicle : public Vehicle
{
    public:
    SportsVehicle():Vehicle(new SpecialDriveStrategy)
    { }
};

class OffRoadVehicle : public Vehicle
{
    public:
    OffRoadVehicle():Vehicle(new SpecialDriveStrategy)
    { }
};

class PassengerVehicle : public Vehicle
{
    public:
    PassengerVehicle():Vehicle(new NormalDriveStrategy)
    { }
};

int main() {
    OffRoadVehicle *ob1 = new OffRoadVehicle;
    PassengerVehicle *ob2 = new PassengerVehicle;
    SportsVehicle *ob3 = new SportsVehicle;
    
    ob1->driveVehicle();
    ob2->driveVehicle();
    ob3->driveVehicle();
    return 0;
}
