#include "dhtsensor.h"
#include <dht.h>
#include <esp_timer.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>


void dht_config_data_line_output(struct DhtDataLine * const line) {
    // data line pin configured as input-output
}

void dht_config_data_line_input(struct DhtDataLine * const line) {
    // data line pin configured as input-output
}

void dht_set_data_line_high(struct DhtDataLine * const line) {
    ESP_ERROR_CHECK(gpio_set_level(line->pin, 1));
}

void dht_set_data_line_low(struct DhtDataLine * const line) {
    ESP_ERROR_CHECK(gpio_set_level(line->pin, 0));
}

enum DhtDataLevel dht_get_data_line_level(struct DhtDataLine * const line) {
    return gpio_get_level(line->pin);
}

void dht_delay_ms(unsigned ms) {
    unsigned delay = (ms + portTICK_PERIOD_MS - 1) / portTICK_PERIOD_MS;
    vTaskDelay(delay);
}

unsigned dht_get_microseconds(void) {
    return (unsigned)esp_timer_get_time();
}
