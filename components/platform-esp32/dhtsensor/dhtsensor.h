#ifndef DHTSENSOR_H_
#define DHTSENSOR_H_

#include <stdint.h>
#include <thsensor.h>
#include <dht.h>


struct DhtDataLine {
    uint32_t pin;
};

struct DhtSensor {
    struct THSensor base;
    struct DhtDataLine data_line;
    struct Dht dht;
};


void dhtsensor_init(struct DhtSensor * const self, uint32_t pin);

#endif /* DHTSENSOR_H_ */
