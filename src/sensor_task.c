#include "sensor_task.h"
#include "sensor_data.h"
#include <stdio.h>

void sensor_task(void *pvParameters) {
    QueueHandle_t queue = (QueueHandle_t) pvParameters;
    const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
    
    while(1) {
        printf("Task Sensor: coletando dados...\n");
        
        sensor_data_t data;
        data.temp = 16.21 + ((float)rand() / RAND_MAX) * 5.0;  // Simulação mais realista
        data.umid = 32.0 + ((float)rand() / RAND_MAX) * 20.0;

        if (xQueueSend(queue, &data, 10) == pdTRUE) {
            printf("Task Sensor: dados enviados (T=%.2f, U=%.2f)\n", data.temp, data.umid);
        } else {
            printf("Task Sensor: fila cheia!\n");
        }
        
        vTaskDelay(xDelay);
    }
}