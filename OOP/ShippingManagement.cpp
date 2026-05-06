#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//=================================================
//           INTERFACE DEFINITIONS
//=================================================

class Trackable {
    public:
        virtual string getCurrentLocation() const = 0;
        virtual int getStatus() const = 0;
        virtual void updateLocation(string location) = 0;
};

class Payable {
    public:
        virtual double calculateFee() const = 0;
        virtual void applyDiscount(double percent) = 0;
};

//=================================================
//               CLASS DEFINITIONS
//=================================================
class Driver; // Forward declaration

// ==========  Vehicle class ==========
class Vehicle : public Trackable {
    private:
        string licensePlate;
        int capacity; 
        string currentLocation;
        int status; // 0: idle, 1: in transit, 2: maintenance
        Driver* assignedDriver;

    public:
        Vehicle(string plate, string location, int status){
            this->setLicensePlate(plate);
            this->setCurrentLocation(location);
            this->setStatus(status);
            this->setAssignedDriver(nullptr);
        }
        Vehicle(string plate, string location) : Vehicle(plate, location, 0) {}
        Vehicle(string plate) : Vehicle(plate, "", 0) {}
        Vehicle() : Vehicle("", "", 0) {}

        // Setters
        void setLicensePlate(string plate) {
            this->licensePlate = plate;
        }
        void setCurrentLocation(string location) {
            this->currentLocation = location;
        }
        void setStatus(int status) {
            this->status = status;
        }
        void setAssignedDriver(Driver* driver) {
            this->assignedDriver = driver;
        }

        // Getters
        string getLicensePlate() const {
            return this->licensePlate;
        }
        string getCurrentLocation() const override {
            return this->currentLocation;
        }
        int getStatus() const override {
            return this->status;
        }
        Driver* getAssignedDriver() const {
            return this->assignedDriver;
        }

        // Trackable interface implementation
        void updateLocation(string location) override {
            this->currentLocation = location;
        }

        // Additional methods
        void displayInfo() const {
            cout << "Vehicle ID: " << this->vehicleId << endl;
            cout << "License Plate: " << this->licensePlate << endl;
            cout << "Current Location: " << this->currentLocation << endl;
            cout << "Status: " << (this->status == 0 ? "Idle" : (this->status == 1 ? "In Transit" : "Maintenance")) << endl;
        }

        int isAvailable() const {
            return this->status == 0;
        }
};

class Truck : public Vehicle {
    private:
        string truckType; // e.g., "Flatbed", "Standard", "Refrigerated"
        int maxLoad;

    public:
        Truck(string plate, string location, int status, string type, int load, string truckType, int maxLoad) : Vehicle(plate, location, status) {
            this->setTruckType(truckType);
            this->setMaxLoad(maxLoad);
        }
        Truck(string plate, string location, string type, int load) : Truck(plate, location, 0, type, load, "Unknown", 0) {}
        Truck(string plate, string type, int load) : Truck(plate, "", 0, type, load, "Unknown", 0) {}
        Truck(string plate) : Truck(plate, "", 0, "Unknown", 0, "Unknown", 0) {}

        // Setters
        void setTruckType(string type) {
            this->truckType = type;
        }
        void setMaxLoad(int load) {
            this->maxLoad = load;
        }

        // Getters
        string getTruckType() const {
            return this->truckType;
        }
        int getMaxLoad() const {
            return this->maxLoad;
        }

        // Additional methods
        void displayInfo() const {
            Vehicle::displayInfo();
            cout << "Truck Type: " << this->truckType << endl;
            cout << "Max Load: " << this->maxLoad << " tons" << endl;
        }
};

class Motorbike : public Vehicle {
    private:
        int maxLoad; // in kg

    public:
        Motorbike(string plate, string location, int status, int load, int maxLoad) : Vehicle(plate, location, status) {
            this->setMaxLoad(maxLoad);
        }
        Motorbike(string plate, string location, int load) : Motorbike(plate, location, 0, load, 0) {}
        Motorbike(string plate, int load) : Motorbike(plate, "", 0, load, 0) {}
        Motorbike(string plate) : Motorbike(plate, "", 0, 0, 0) {}

        // Setters
        void setMaxLoad(int load) {
            this->maxLoad = load;
        }

        // Getters
        int getMaxLoad() const {
            return this->maxLoad;
        }

        // Additional methods
        void displayInfo() const {
            Vehicle::displayInfo();
            cout << "Motorbike Max Load: " << this->maxLoad << " kg" << endl;
        }
};

// ========== Shipment class ==========
class Shipment : public Trackable, public Payable {
    private:
        string shipmentId;
        string sender;
        string receiver;
        double weightKg; // in kg
        string origin;
        string destination;
        string currentLocation;
        int status; // 0: pending, 1: in transit, 2: delivered, -1: cancelled

    public:
        Shipment(string id, string sender, string receiver, double weight, string origin, string destination) {
            this->shipmentId = id;
            this->sender = sender;
            this->receiver = receiver;
            this->weightKg = weight;
            this->origin = origin;
            this->destination = destination;
            this->currentLocation = origin;
            this->status = 0; // pending by default
        }

        // Setters
        void setShipmentId(string id) {
            this->shipmentId = id;
        }
        void setSender(string sender) {
            this->sender = sender;
        }
        void setReceiver(string receiver) {
            this->receiver = receiver;
        }
        void setWeightKg(double weight) {
            this->weightKg = weight;
        }
        void setOrigin(string origin) {
            this->origin = origin;
        }
        void setDestination(string destination) {
            this->destination = destination;
        }
        void setStatus(int status) {
            this->status = status;
        }

        // Getters
        string getShipmentId() const {
            return this->shipmentId;
        }
        string getSender() const {
            return this->sender;
        }
        string getReceiver() const {
            return this->receiver;
        }
        double getWeightKg() const {
            return this->weightKg;
        }
        string getOrigin() const {
            return this->origin;
        }
        string getDestination() const {
            return this->destination;
        }
        int getStatus() const override {
            return this->status;
        }

        // Trackable interface implementation
        string getCurrentLocation() const override {
            return this->currentLocation;
        }

        void updateLocation(string location) override {
            this->currentLocation = location;
            if (location == destination) {
                this->setStatus(2); // delivered
            } else if (location != origin) {
                this->setStatus(1); // in transit
            }
        }

        // Payable interface implementation
        virtual double calculateFee() const = 0;

        void applyDiscount(double percent) override {
            double fee = calculateFee();
            double discount = fee * (percent / 100);
            double discountedFee = fee - discount;
            cout << "Original Fee: $" << fee << endl;
            cout << "Discount: " << percent << "% ($" << discount << ")" << endl;
            cout << "Discounted Fee: $" << discountedFee << endl;
        }

};

class StandardShipment : public Shipment {
    private:
        int estimatedDeliveryDays;

    public:
        StandardShipment(string id, string sender, string receiver, double weight, string origin, string destination) : Shipment(id, sender, receiver, weight, origin, destination) {}      


        double calculateFee() const override {
            return getWeightKg() * 10; // $10 per kg
        }
};

class ExpressShipment : public Shipment {
    private:
        int guaranteedHours;

    public:
        ExpressShipment(string id, string sender, string receiver, double weight, string origin, string destination) : Shipment(id, sender, receiver, weight, origin, destination) {}      

        double calculateFee() const override {
            double baseFee = Shipment::calculateFee();
            return baseFee * 25;
        }
};

class FragileShipment : public Shipment {
    private:
        int insuranceValue;

    public:
        FragileShipment(string id, string sender, string receiver, double weight, string origin, string destination, int insuranceValue) : Shipment(id, sender, receiver, weight, origin, destination) {
            this->setInsuranceValue(insuranceValue);
        }

        void setInsuranceValue(int value) {
            this->insuranceValue = value;
        }
        int getInsuranceValue() const {
            return this->insuranceValue;
        }

        double calculateFee() const override {
            double baseFee = Shipment::calculateFee();
            double insuranceFee = insuranceValue * 0.01; // 1% of insurance value
            return baseFee*20 + insuranceFee;
        }
};

// ========== Manegement System class ==========
class Driver{
    // driver is assigned to one vehicle, and a vehicle can only have one driver
    private:
        string driverId;
        string name;
        string licenseType; //A = motorbike, C = truck
        Vehicle* assignedVehicle;
        int status; // 0: available, 1: on duty, 2: off duty

    public:
        Driver(string id, string name, string licenseType, Vehicle* assignedVehicle, int status)
        {
            this->setDriverId(id);
            this->setName(name);
            this->setLicenseType(licenseType);
            this->setAssignedVehicle(assignedVehicle);
            this->setStatus(status);
        }
        Driver(string id, string name, string licenseType) : Driver(id, name, licenseType, nullptr, 0) {}
        Driver(string id, string name) : Driver(id, name, "", nullptr, 0) {}
        Driver(string id) : Driver(id, "", "", nullptr, 0) {}
        Driver() : Driver("", "", "", nullptr, 0) {}

        // Setters
        void setDriverId(string id) {
            this->driverId = id;
        }
        void setName(string name){
            this->name = name;
        }
        void setLicenseType(string licenseType){
            this->licenseType = licenseType;
        }
        void setAssignedVehicle(Vehicle* vehicle){
            this->assignedVehicle = vehicle;
            vehicle->setAssignedDriver(this); 
        }
        void setStatus(int status){
            this->status = status;
        }

        // Getters
        string getDriverId() {
            return this->driverId;
        }
        string getName() {
            return this->name;
        }
        string getLicenseType() {
            return this->licenseType;
        }
        Vehicle* getAssignedVehicle() {
            return this->assignedVehicle;
        }
        int getStatus() {
            return this->status;
        }

        // Additional methods
        void displayInfo() {
            cout << "Driver ID: " << this->driverId << endl;
            cout << "Name: " << this->name << endl;
            cout << "License Type: " << this->licenseType << endl;
            cout << "Status: " << (this->status == 0 ? "Available" : (this->status == 1 ? "On Duty" : "Off Duty")) << endl;
            if (assignedVehicle != nullptr) {
                cout << "Assigned Vehicle: " << assignedVehicle->getLicensePlate() << endl;
            } else {
                cout << "Assigned Vehicle: None" << endl;
            }
        }

        void startShift() {
            if (status == 0) {
                setStatus(1); // on duty
                cout << name << " has started their shift." << endl;
            } else {
                cout << name << " cannot start shift. Current status: " << (status == 1 ? "On Duty" : "Off Duty") << endl;
            }
        }

        void endShift() {
            if (status == 1) {
                setStatus(0); // available
                cout << name << " has ended their shift." << endl;
            } else {
                cout << name << " cannot end shift. Current status: " << (status == 0 ? "Available" : "Off Duty") << endl;
            }
        }
};

class LogisticCompanyManagement {
    private:
        vector<Vehicle*> vehicles;
        vector<Shipment*> shipments;
        vector<Driver*> drivers;

    public:
        void addVehicle(Vehicle* vehicle) {
            vehicles.push_back(vehicle);
        }
        void addShipment(Shipment* shipment) {
            shipments.push_back(shipment);
        }
        void addDriver(Driver* driver) {
            drivers.push_back(driver);
        }

        // Additional methods for managing the system can be added here
        void createShipment(string id, string sender, string receiver, double weightKg, string origin, string destination) {
            Shipment* newShipment = new StandardShipment(id, sender, receiver, weightKg, origin, destination);
            addShipment(newShipment);
            cout << "Created new shipment with ID: " << id << endl;
        }

        void assignDriverToVehicle(string driverId, string licensePlate) {
            Driver* driver = nullptr;
            Vehicle* vehicle = nullptr;

            for (Driver* d : drivers) {
                if (d->getDriverId() == driverId) {
                    driver = d;
                    break;
                }
            }

            for (Vehicle* v : vehicles) {
                if (v->getLicensePlate() == licensePlate) {
                    vehicle = v;
                    break;
                }
            }

            if (driver && vehicle && vehicle->isAvailable() && driver->getStatus() == 0 && ((driver->getLicenseType() == "A" && dynamic_cast<Motorbike*>(vehicle)) || (driver->getLicenseType() == "C" && dynamic_cast<Truck*>(vehicle)))) {
                driver->setAssignedVehicle(vehicle);
                cout << "Driver " << driver->getName() << " assigned to vehicle " << vehicle->getLicensePlate() << endl;
            } else {
                cout << "Failed to assign driver to vehicle." << endl;
            }
        }

        void assignShipmentToVehicle(string shipmentId) {
            Shipment* shipment = nullptr;
            Vehicle* vehicle = nullptr;

            // 1. Tìm đơn hàng theo ID
            for (Shipment* s : shipments) {
                if (s->getShipmentId() == shipmentId) {
                    shipment = s;
                    break;
                }
            }
        


            if (!shipment) {
                cout << "Shipment not found." << endl;
                return;
            }

            double weight = shipment->getWeightKg();

            // 2. Tìm xe phù hợp dựa trên khối lượng
            for (Vehicle* v : vehicles) {
                if (v->isAvailable()) {
                    if (weight <= 30) {
                        Motorbike* mb = dynamic_cast<Motorbike*>(v);
                        if (mb && mb->getMaxLoad() >= weight) {
                            vehicle = mb;
                            break;
                        }
                    } 
                    else {
                        Truck* tr = dynamic_cast<Truck*>(v);
                        if (tr && tr->getMaxLoad() >= weight) {
                            vehicle = tr;
                            break;
                        }
                    }   
                }
            }

            if (vehicle) {
                vehicle->setStatus(1); 
                shipment->updateLocation(vehicle->getCurrentLocation());
        
                cout << "Success: Shipment " << shipmentId 
                    << " (" << weight << "kg) assigned to " 
                    << (weight <= 30 ? "Motorbike " : "Truck ") 
                    << vehicle->getLicensePlate() << endl;
            } else {
                cout << "Failed: No available " 
                    << (weight <= 30 ? "Motorbike" : "Truck") 
                    << " can carry this weight." << endl;
            }
        }   
};


int main() {
    cout << "Welcome to the Shipping Management System!" << endl;
}







