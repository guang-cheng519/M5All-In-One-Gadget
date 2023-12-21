#include "MdMeasureDistance.h"
#include "M5All-In-One-Gadget.h"
#include "DrUltraSonic.h"

DrUltraSonic drul=DrUltraSonic(ECHO_PIN, TRIG_PIN);

double MdMeasureDistance::getDistance()
{
    double distance = (340.0 / 1000000) * drul.measureReturnTime() * 0.5 * 100;

    return distance;
}
