#include "serialpublisher.h"
#include <esp_log.h>

#define TAG "SerialPublisher"

static int serialpublisher_publish_indoor_temp(struct Publisher * const self, int temp);
static int serialpublisher_publish_indoor_humidity(struct Publisher * const self, int humidity);


void serialpublisher_init(struct SerialPublisher * const self) {
    self->base.publish_indoor_temp = serialpublisher_publish_indoor_temp;
    self->base.publish_indoor_humidity = serialpublisher_publish_indoor_humidity;
}


static int serialpublisher_publish_indoor_temp(struct Publisher * const self, int temp) {
    ESP_LOGI(TAG, "Indoor temperature: %d C", temp);
    return 0;
}

static int serialpublisher_publish_indoor_humidity(struct Publisher * const self, int humidity) {
    ESP_LOGI(TAG, "Indoor humidity: %d %%", humidity);
    return 0;
}
