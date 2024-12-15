#include "os.h"
#include <freertos/FreeRTOS.h>
#include <esp_log.h>
#include <app.h>

#define TAG "OS"

// Indoor sensor task
#define APP_INDOOR_SENSOR_TASK_NAME         "app_indoor_sensor_task"
#define APP_INDOOR_SENSOR_TASK_STACK_SIZE   4096 // exact size between 1800 (not working) and 1900 (working)
#define APP_INDOOR_SENSOR_TASK_PRIORITY     5
#define APP_INDOOR_SENSOR_TASK_INTERVAL_MS  2000
static void app_indoor_sensor_task(void * pvParameters);
static StaticTask_t app_indoor_sensor_struct;
static StackType_t app_indoor_sensor_stack[APP_INDOOR_SENSOR_TASK_STACK_SIZE];

void os_init(void) {
    xTaskCreateStatic(app_indoor_sensor_task,
                      APP_INDOOR_SENSOR_TASK_NAME,
                      APP_INDOOR_SENSOR_TASK_STACK_SIZE,
                      NULL,
                      APP_INDOOR_SENSOR_TASK_PRIORITY,
                      app_indoor_sensor_stack,
                      &app_indoor_sensor_struct);
}

static void app_indoor_sensor_task(void * pvParameters) {
    const int DELAY = APP_INDOOR_SENSOR_TASK_INTERVAL_MS / portTICK_PERIOD_MS;

    for ( ;; ) {
        vTaskDelay(DELAY);
        app_read_and_publish_indoor_sensor();
    }
}

