/*
* Amazon Interview Preperation
* Design a parking lot using object oriented design principles
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> //srand, rand
using namespace std;

enum VehicleSize {
	Motorcycle,
	Compact,
	Large,
};

class Level {
    int floor;
    vector<ParkingSpot*> spots;
    int availableSpots = 0; // number of free spots
    static const int SPOTS_PER_ROW = 10;

	/* Park a vehicle starting at the spot spotNumber, and continuing until vehicle.spotsNeeded. */
	bool parkStartingAtSpot(int spotNumber, Vehicle vehicle) {
		vehicle.clearSpots();
		bool success = true;
		for (int i = spotNumber; i < spotNumber + vehicle.getSpotsNeeded(); i++) {
			success = spots[i]->park(vehicle);
		}
		availableSpots -= vehicle.getSpotsNeeded();
		return success;
	}

	/* find a spot to park this vehicle. Return index of spot, or -1 on failure. */
	int findAvailableSpots(Vehicle vehicle) {
		int spotsNeeded = vehicle.getSpotsNeeded();
		int lastRow = -1;
		int spotsFound = 0;
		for (int i = 0; i < spots.size(); i++) {
			ParkingSpot spot = *spots[i];
			if (lastRow != spot.getRow()) {
				spotsFound = 0;
				lastRow = spot.getRow();
			}
			if (spot.canFitVehicle(vehicle)) {
				spotsFound++;
			}
			else {
				spotsFound = 0;
			}
			if (spotsFound == spotsNeeded) {
				return i - (spotsNeeded - 1);
			}
		}
		return -1;
	}

public:
	Level(){
		floor = 0;
		spots = {};
	}
	Level(int flr, int numberSpots) {
		floor = flr;
		int largeSpots = numberSpots / 4;
		int bikeSpots = numberSpots / 4;
		int compactSpots = numberSpots - largeSpots - bikeSpots;
		for (int i = 0; i < numberSpots; i++) {
			VehicleSize sz = VehicleSize::Motorcycle;
			if (i < largeSpots) {
				sz = VehicleSize::Large;
			}
			else if (i < largeSpots + compactSpots) {
				sz = VehicleSize::Compact;
			}
			int row = i / SPOTS_PER_ROW;
			spots[i] = new ParkingSpot(*this, row, i, sz);
		}
		availableSpots = numberSpots;
	}

	int availableFreeSpots() {
		return availableSpots;
	}

	/* Try to find a place to park this vehicle. Return false if failed. */
	bool parkVehicle(Vehicle vehicle) {
		if (availableFreeSpots() < vehicle.getSpotsNeeded()) {
			return false;
		}
		int spotNumber = findAvailableSpots(vehicle);
		if (spotNumber < 0) {
			return false;
		}
		return parkStartingAtSpot(spotNumber, vehicle);
	}

	void print() {
		int lastRow = -1;
		for (int i = 0; i < spots.size(); i++) {
			ParkingSpot spot = *spots[i];
			if (spot.getRow() != lastRow) {
				cout <<"  "<<endl;
				lastRow = spot.getRow();
			}
			spot.print();
		}
	}

	/* When a car was removed from the spot, increment availableSpots */
	void spotFreed() {
		availableSpots++;
	}
};

class ParkingSpot {
	Vehicle *vehicle;
	VehicleSize spotSize;
	int row;
	int spotNumber;
	Level level;

public:
	ParkingSpot(Level lvl, int r, int n, VehicleSize sz) {
		level = lvl;
		row = r;
		spotNumber = n;
		spotSize = sz;
	}

	bool isAvailable() {
		return (vehicle == nullptr);
	}

	/* Checks if the spot is big enough for the vehicle (and is available). This compares
	* the SIZE only. It does not check if it has enough spots. */
	bool canFitVehicle(Vehicle vehicle) {
		return isAvailable() && vehicle.canFitInSpot(*this);
	}

	/* Park vehicle in this spot. */
	bool park(Vehicle v) {
		if (!canFitVehicle(v)) {
			return false;
		}
		*vehicle = v;
		vehicle->parkInSpot(*this);
		return true;
	}

	int getRow() {
		return row;
	}

	int getSpotNumber() {
		return spotNumber;
	}

	VehicleSize getSize() {
		return spotSize;
	}

	/* Remove vehicle from spot, and notify level that a new spot is available */
	void removeVehicle() {
		level.spotFreed();
		vehicle = NULL;
	}

	void print() {
		if (vehicle->getSize() == NULL) {
			if (spotSize == VehicleSize::Compact) {
				cout << "c" << endl;
			}
			else if (spotSize == VehicleSize::Large) {
				cout << "l" << endl;
			}
			else if (spotSize == VehicleSize::Motorcycle) {
				cout<<"m"<<endl;
			}
		}
		else {
			vehicle->print();
		}
	}
};

 class Vehicle {
 protected:	
	vector<ParkingSpot> parkingSpots;
	string licensePlate;
	int spotsNeeded;
	VehicleSize size;

 public:
	int getSpotsNeeded() {
		return spotsNeeded;
	}

	VehicleSize getSize() {
		return size;
	}

	/* Park vehicle in this spot (among others, potentially) */
	void parkInSpot(ParkingSpot spot) {
		parkingSpots.push_back(spot);
	}

	/* Remove car from spot, and notify spot that it's gone */
	void clearSpots() {
		for (int i = 0; i < parkingSpots.size(); i++) {
			parkingSpots.at(i).removeVehicle();
		}
		parkingSpots.clear();
	}

	bool canFitInSpot(ParkingSpot spot);
	void print();
 };

 class Bus : public Vehicle {
    public: 
	Bus() {
		 spotsNeeded = 5;
		 size = VehicleSize::Large;
	 }

	bool canFitInSpot(ParkingSpot spot) {
		 return spot.getSize() == VehicleSize::Large;
	 }

	 void print() {
		 cout << "B"<<endl;
	 }
 };

class Car : public Vehicle {
 public:
	 Car() {
		 spotsNeeded = 1;
		 size = VehicleSize::Compact;
	 }

	 bool canFitInSpot(ParkingSpot spot) {
		 return spot.getSize() == VehicleSize::Large || spot.getSize() == VehicleSize::Compact;
	 }

	 void print() {
		 cout << "C" << endl;
	 }
 };

class MotorCycle : public Vehicle {
public:
	MotorCycle() {
		spotsNeeded = 1;
		size = VehicleSize::Compact;
	}

	bool canFitInSpot(ParkingSpot spot) {
		return true;
	}

	void print() {
		cout << "M" << endl;
	}
};

class ParkingLot {
	vector<Level*> levels;
	const int NUM_LEVELS = 5;

public:
	ParkingLot() {
		for (int i = 0; i < NUM_LEVELS; i++) {
			levels[i] = new Level(i, 30);
		}
	}

	/* Park the vehicle in a spot (or multiple spots). Return false if failed. */
	 bool parkVehicle(Vehicle vehicle) {
		for (int i = 0; i < levels.size(); i++) {
			if (levels[i]->parkVehicle(vehicle)) {
				return true;
			}
		}
		return false;
	}

	void print() {
		for (int i = 0; i < levels.size(); i++) {
			cout<<"Level"<< i << ": ";
			levels[i]->print();
			cout << endl;
		}
		cout << endl;
	}
};

 int main(){
	 ParkingLot* lot = new ParkingLot();

	 Vehicle* v;
	 while (v == NULL || lot->parkVehicle(*v)) {
		 lot->print();
		 int r = rand() % 10 +  1;
		 if (r < 2) {
			 v = new Bus();
		 }
		 else if (r < 4) {
			 v = new MotorCycle();
		 }
		 else {
			 v = new Car();
		 }
		 cout<<"\nParking a "<<endl;
		 v->print();
		 cout << endl;
	 }
	 cout<<"Parking Failed. Final state: "<<endl;
	 lot->print();
	 return 0;
 }