#ifndef QUEUE_MANAGER_H
#define QUEUE_MANAGER_H

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

QueueHandle_t queue_manager_create(uint32_t queue_length, uint32_t item_size);
void queue_manager_delete(QueueHandle_t queue);

#endif