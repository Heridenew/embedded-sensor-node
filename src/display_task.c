#include "display_task.h"
#include "sensor_data.h"
#include <stdio.h>

void display_task(void *pvParameters) {
    QueueHandle_t queue = (QueueHandle_t) pvParameters;
    const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
    
    while(1) {
        sensor_data_t received;
        
        if (xQueueReceive(queue, &received, 100) == pdPASS) {
            printf("=== DISPLAY ===\n");
            printf("Temperatura: %.2f °C\n", received.temp);
            printf("Umidade: %.2f %%\n", received.umid);
            printf("===============\n");
        } else {
            printf("Display: aguardando dados...\n");
        }
        
        vTaskDelay(xDelay);
    }
}