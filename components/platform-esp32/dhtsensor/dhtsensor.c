#include "dhtsensor.h"
#include <driver/gpio.h>
#include <esp_log.h>

#define TAG "DhtSensor"

#define THSENSOR_TO_DHTSENSOR(thsensor) ((struct DhtSensor *)(thsensor))

#define DHTSENSOR_LOG_RESULT_OK "DhtSensor: Result OK"
#define DHTSENSOR_LOG_CRC_ERROR "DhtSensor: Data consistency error during the data read"
#define DHTSENSOR_LOG_TIMEOUT "DhtSensor: Timeout error during the data read"
#define DHTSENSOR_LOG_UNEXPECTED_ERROR "DhtSensor: Unexpected error during the data read"


static inline void dht_data_line_init(struct DhtDataLine * const data_line, uint32_t pin);
static int dhtsensor_get_data(struct THSensor * const self, struct THData * const data);
static inline void dhtsensor_log_result(enum DhtResult result);


void dhtsensor_init(struct DhtSensor * const self, uint32_t pin) {
    dht_data_line_init(&self->data_line, pin);
    dht_init(&self->dht, &self->data_line);

    self->base.get_data = dhtsensor_get_data;
}


static void dht_data_line_init(struct DhtDataLine * const data_line, uint32_t pin) {
    data_line->pin = pin;

    const gpio_config_t config = {
        .pin_bit_mask = (1 << data_line->pin),
        .mode = GPIO_MODE_INPUT_OUTPUT_OD,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    ESP_ERROR_CHECK(gpio_config(&config));
    ESP_ERROR_CHECK(gpio_set_level(data_line->pin, 1));
}

static int dhtsensor_get_data(struct THSensor * const self, struct THData * const data) {
    struct Dht * dht = &THSENSOR_TO_DHTSENSOR(self)->dht;

    struct DhtData dht_data;
    enum DhtResult result = dht_read_data(dht, &dht_data);
    
    dhtsensor_log_result(result);

    if (result == DHT_OK) {
        data->humidity = dht_data.humidity.integral;
        data->temperature = dht_data.temperature.integral;
    }

    return result;
}

static inline void dhtsensor_log_result(enum DhtResult result) {
    switch (result) {
        case DHT_OK:
            ESP_LOGI(TAG, DHTSENSOR_LOG_RESULT_OK);
            break;
        case DHT_ERR_CRC:
            ESP_LOGE(TAG, DHTSENSOR_LOG_CRC_ERROR);
            break;
        case DHT_ERR_TIMEOUT:
            ESP_LOGE(TAG, DHTSENSOR_LOG_TIMEOUT);
            break;
        default:
            ESP_LOGE(TAG, DHTSENSOR_LOG_UNEXPECTED_ERROR);
            break;
    }
}
