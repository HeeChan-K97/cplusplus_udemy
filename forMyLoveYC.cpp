//main.cpp

#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <vector>

#include "analysis.h"

void printOrderStats(std::vector<CarInterface *> cars, std::vector<unsigned int> order)
{
    for (unsigned int i = 0; i < cars.size(); i++)
    {
        std::cout << cars.at(i)->getMake() << " " << cars.at(i)->getModel() << " odo:" << cars.at(i)->getOdometry() << " odo:" << cars.at(i)->getCurrentSpeed() << " position:" << order.at(i) << std::endl;
    }
}

int main(void)
{

    std::vector<CarInterface *> cars;
    //! @todo
    //! TASK 1
    //! Create 3 cars with follwing specifications

    // Mercedes - C180
    // height = 1.45 m, width = 1.77 m, power = 143 HP, drag coefficient = 0.29, weight = 1200 kg
    Car.assign
    Car carMercedes("Mercedes", "C180", 1.45, 1.77, 143.0, 0.29, 1200.0);
    // Bugatti - Veyron
    // height = 1.19 m, width = 2.00 m, power P = 1200 HP, drag coefficient = 0.35, weight = 2200 kg
    Car carBugatti("Bugatti", "Veyron", 1.19, 2.00, 1200.0, 0.35, 2200.0);
    // Toyota - Yaris_WRsC
    // height = 1.19 m, width = 1.87 m, power P = 420 HP, drag coefficient = 0.30, weight = 1190 kg
    Car carToyota("Toyota", "Yaris_WRsC", 1.19, 1.87, 420.0, 0.3, 1190.0);
    // Car carMercedes;
    // carMercedes.setMake = "Mercedes";
    // carMercedes.setModel "C180";
    // carMercedes.height = 1.45;
    // carMercedes.width

    std::shared_ptr<DisplayRace> raceDisplay(new DisplayRace(cars));

    // We create a pointer to the Radar, will use a shared pointer here
    std::shared_ptr<Analysis> analysisPtr(new Analysis(cars, raceDisplay));

    // The below is just a demo race, to show how to accelerate and decelerate the cars.
    // You have to keep accelerating to go fast, and decelerate to slow down
    // STUDENTS: Comment it out, not needed for other tasks.
    analysisPtr->demoRace();

    // We call TASK 1
    {
        std::vector<unsigned int> order = analysisPtr->sortByOdometry();
        printOrderStats(cars, order);
    }

    // We call TASK 2
    {
        std::vector<unsigned int> order = analysisPtr->dragRace(1000.0);
        printOrderStats(cars, order);
    }

    // We call TASK 3
    analysisPtr->stopAllCars();

    // We call TASK 4
    {
        std::vector<unsigned int> order = analysisPtr->zeroTopZeroRace();
        printOrderStats(cars, order);
    }

    return 0;
}


//---------------------------------------------------analysis.cpp-----------------------------------------------------------------------------//


#include "analysis.h"

using std::vector;
using std::pair;

//! @todo
//! TASK 1 - We need to store cars in the Analysis class, how to do this?
Analysis::Analysis(std::vector<CarInterface*> cars) :
    cars_(cars),raceDisplay_(nullptr)
{

}

Analysis::Analysis(std::vector<CarInterface*> cars,std::shared_ptr<DisplayRace> raceDisplay) :
    cars_(cars),raceDisplay_(raceDisplay)
{

}

//! @todo
//! TASK 1 - Refer to README.md and the Header file for full description
std::vector<unsigned int> Analysis::sortByOdometry(){

    std::vector<unsigned int> order(cars_.size(),0);//Creating a vector, same size as cars with all zeros


    return order;
}

//! @todo
//! TASK 2 - Refer to README.md and the Header file for full description
std::vector<unsigned int> Analysis::dragRace(double distance){

    std::vector<unsigned int> order(cars_.size(),0);

    return order;
}


//! @todo
//! TASK 3 - Refer to README.md and the Header file for full description
void Analysis::stopAllCars(){

}

//! @todo
//! TASK 4 - Refer to README.md and the Header file for full description
std::vector<unsigned int> Analysis::zeroTopZeroRace(){

    std::vector<unsigned int> order(cars_.size(),0);//Creating a vector, same size as cars with all zeros

    return order;
}

// Demo code
void Analysis::demoRace(){


    //This is an example of how to draw 3 cars moving
    // accelerate 300 times
    unsigned int count=0;

    while(count < 300){
        for(auto car : cars_){
          car->accelerate();
        }
        if(raceDisplay_!=nullptr){
            raceDisplay_->updateDisplay();
        }
        count++;
    }

    // decelerate 600 times
    count =0;
    while(count < 600){
        for(auto car : cars_){
          car->decelerate();
        }
        if(raceDisplay_!=nullptr){
            raceDisplay_->updateDisplay();
        }
        count++;
    }

}

//------------------------------------------------analysis.h--------------------------------------------------------------------------------//

#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>
#include <thread>
#include "car.h"
#include "display_race.h"

class Analysis
{
public:
    /**
     * @brief Constructor for class
     * @param vector of pointers to CarInterface
     */
    Analysis(std::vector<CarInterface *> cars);
    /**
     * @brief Constructor for class
     * @param vector of pointers to CarInterface
     * @param raceDisplay pointer, enabling us to visualise the race
     */
    Analysis(std::vector<CarInterface*> cars,std::shared_ptr<DisplayRace> raceDisplay);

    /**
     * @brief Standard drag race
     * Create a drag racing algorithm, where each vehicle will race a distance of 1km and then stop. So the logic for `dragRace` is:
     * 1. Accelerating each car
     * 2. When each car covers set distance the race is finished, we declare the winner and terminate the race.
     * Return the order of vehicles that covered the distance
     * @param set distance for race
     * @return order of cars (the vector has same size as the number of cars in race), each element is the position of the respective car in the race
     */
    std::vector<unsigned int> dragRace(double distance);

    /**
     * @brief Stop all the cars (this function ensure their speed is zero)
     */
    void stopAllCars();

    /**
     * @brief
     * Create a drag race algortithm, where all cars get to top speed and then back to zero, quickest to do so wins race. So the logic for the `dragRace` is :
     * 1. Accelerate all cars
     * 2. As each individual vehicle reaches top speed then decelerate that vehicle.
     * 3. When all vehicles have stopped, terminate the race
     * @return order of cars (the vector has same size as the number of cars in race), each element is the position of the respective car in the race
     */
    std::vector<unsigned int> zeroTopZeroRace();


    /**
     * @brief
     * Sort the cars by their odometry
     * @return asceding order of cars (the vector has same size as the number of cars in race), each element in vector contains the car ID, positions in vector is in order using odometry (lowest position has lowest number of kilometers)
     */
    std::vector<unsigned int> sortByOdometry();

    /**
     * @brief
     * Demo of racing, accelerates the cars 300 times, deccelerates 600 times.
     */
    void demoRace();

private:
    std::vector<CarInterface*> cars_;
    std::shared_ptr<DisplayRace> raceDisplay_;
};

#endif // ANALYSIS_H

