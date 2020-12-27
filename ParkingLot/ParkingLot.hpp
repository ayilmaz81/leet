#pragma once
#include <unordered_map>
#include <vector>
#include <string>

namespace PARKING
{
    class Ticket;
    class Payment;
    class ParkingFloor;
    class ParkingSpot;
    class EntryPoint;
    class ExitPoint;
    class Vehicle;
    
    class Account
    {
    protected:
        std::string name;

    public:
    };
    class Admin : public Account
    {
    public:
        void addParkingSpot(ParkingFloor &floor, ParkingSpot &spot);
        void removeParkingSpot(ParkingSpot &spot);
        void addEntryPoint(EntryPoint &entry);
        void addExitPoint(ExitPoint &exit);
        void rempveEntryPoint(EntryPoint &entry);
        void removeExitPoint(ExitPoint &exit);
    };
    class Attendent : public Account
    {
    public:
        void acceptPayment(Ticket &ticket);
    };
    class Customer : public Account
    {
    public:
        Ticket takeTicket(Vehicle &vehicle);
    };
    class AbstractVehicle
    {
    public:
        enum class TYPE
        {
            CAR,
            TRUCK,
            VAN,
            MOTORCYCLE
        };
    };

    class Vehicle : public AbstractVehicle
    {
    public:
    };
    class ElectricVehicle : AbstractVehicle
    {
    public:
    };
    class ParkingSpot
    {
    public:
        int id;
        enum class TYPE
        {
            COMPACT,
            LARGE,
            HANDICAPPED,
            MOTORCYCLE
        };
    };

    class RegularSpot : public ParkingSpot
    {
    };

    class ElectricParkingSpot : public ParkingSpot
    {
    };

    class EntryPoint
    {
    public:
        Ticket CreateTicket(Vehicle &vehicle);
    };

    class ExitPoint
    {
    public:
        void exit(Ticket &ticket);
    };
    class ParkingFloor
    {
        std::unordered_map<ParkingSpot::TYPE, int> freeSpots;
        std::vector<ParkingSpot *> spots;
        int floorNumber;

    public:
        const std::vector<ParkingSpot *> getParkingSpots() const;
        bool addParkingSpot(const ParkingSpot::TYPE &type, bool isElectric);
        bool removeParkingSpot(int id);

        std::string displayFreeParkingSlots() const;
    };

    class ParkingLot
    {
    public:
        std::vector<ParkingFloor> floors;
        std::vector<EntryPoint> entryPoints;
        std::vector<ExitPoint> exitPoints;
    };

    class Ticket
    {
    public:
        int fee;
        Vehicle &vehicle;
        size_t entryTime;
        size_t exitTime;
    };

} // namespace PARKING