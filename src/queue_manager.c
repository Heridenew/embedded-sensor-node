#include "queue_manager.h"
#include <stdio.h>

QueueHandle_t queue_manager_create(uint32_t queue_length, uint32_t item_size) {
    QueueHandle_t queue = xQueueCreate(queue_length, item_size);
    if (queue == NULL) {
        printf("ERRO: Falha ao criar queue\n");
        return NULL;
    }
    printf("Queue criada com sucesso (tamanho: %d, item: %d bytes)\n", 
           queue_length, item_size);
    return queue;
}

void queue_manager_delete(QueueHandle_t queue) {
    if (queue != NULL) {
        vQueueDelete(queue);
        printf("Queue deletada\n");
    }
}