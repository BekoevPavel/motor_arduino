#ifndef DI_hpp
#define DI_hpp
#include "encoder.hpp"
#include "MotorController.hpp"
#include "connect.hpp"
class DI
{
private:
    DI() {}
    DI(const DI &);
    DI &operator=(DI &);

public:
    static DI &getInstance()
    {
        static DI instance;
        return instance;
    }

    MotorController *motorController;
    Encoder *enc;
    ConnectController * uiProg;
};

#endif
