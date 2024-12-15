#include "platform.h"
#include <app.h>
#include <dhtsensor.h>
#include <serialpublisher.h>
#include <os.h>


static struct DhtSensor dht_sensor;
static struct SerialPublisher publisher;

void init(void) {
    dhtsensor_init(&dht_sensor, DHT_DATA_LINE_PIN);
    serialpublisher_init(&publisher);

    app_init((struct THSensor *)&dht_sensor, (struct Publisher *)&publisher);

    os_init();   
}
