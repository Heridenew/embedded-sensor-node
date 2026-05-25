#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sensor_task.h"
#include "display_task.h"
#include "queue_manager.h"
#include "sensor_data.h"

#define QUEUE_LENGTH 10
#define TASK_STACK_SIZE 2048

TaskHandle_t sensorTaskHandle = NULL;
TaskHandle_t displayTaskHandle = NULL;
QueueHandle_t xQueue = NULL;

void app_main() {
    printf("=== EMBEDDED SENSOR NODE ===\n");
    printf("Inicializando sistema...\n");
    
    // Criar queue
    xQueue = queue_manager_create(QUEUE_LENGTH, sizeof(sensor_data_t));
    if (xQueue == NULL) {
        printf("ERRO FATAL: Falha na criação da queue\n");
        return;
    }
    
    // Criar tasks
    BaseType_t ret1 = xTaskCreate(sensor_task, "SensorTask", TASK_STACK_SIZE, xQueue, tskIDLE_PRIORITY, &sensorTaskHandle);
    
    BaseType_t ret2 = xTaskCreate(display_task, "DisplayTask",  TASK_STACK_SIZE, xQueue, tskIDLE_PRIORITY, &displayTaskHandle);
    
    if (ret1 == pdPASS && ret2 == pdPASS) {
        printf("Sistema inicializado com sucesso!\n");
        printf("Tasks criadas: SensorTask, DisplayTask\n");
        printf("Queue criada: %d posições\n", QUEUE_LENGTH);
    } else {
        printf("ERRO: Falha na criação de tasks\n");
        if (xQueue != NULL) {
            queue_manager_delete(xQueue);
        }
    }
}