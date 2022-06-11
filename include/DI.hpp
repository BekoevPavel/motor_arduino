#ifndef DI_hpp
#define DI_hpp
#include "encoder.hpp"
#include "MotorController.hpp"
#include "connect.hpp"
#include "stepper.hpp"
#include " dynamometer.hpp"
class DI
{
private:
    DI() {}
    // DI(const DI &);
    // DI &operator=(DI &);

public:
    // static DI &getInstance()
    // {
    //     static DI instance;
    //     return instance;
    // }

    static MotorController *motorController;
    static Encoder *enc;
    static ConnectController *uiProg;
    static MyStepper *stepper;
    static Dynamometer *dynamometer;
    
};

#endif
