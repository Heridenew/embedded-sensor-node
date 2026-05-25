# Embedded Sensor Node - ESP32

[![PlatformIO](https://img.shields.io/badge/PlatformIO-ESP32-blue)](https://platformio.org/)
[![FreeRTOS](https://img.shields.io/badge/RTOS-FreeRTOS-green)](https://freertos.org/)

## Descrição

Projeto de firmware embarcado para ESP32 utilizando ESP-IDF e FreeRTOS. Implementa arquitetura multitarefa com comunicação entre tasks via Queue (producer/consumer).

## Funcionalidades Implementadas

- ✅ **Multitarefa** com FreeRTOS (SensorTask + DisplayTask)
- ✅ **Comunicação entre tasks** via Queue
- ✅ **Estrutura de dados** compartilhada (sensor_data_t)
- ✅ **Tratamento de erros** na criação de tasks e queue
- ✅ **Simulação de dados** do sensor com variação realista
- ✅ **Modularização** profissional (.h/.c separados)

## Arquitetura
[ SensorTask ] → [ Queue ] → [ DisplayTask ]

## Como usar

# Clone o repositório
git clone https://github.com/Heridenew/embedded-sensor-node.git

# Abra no PlatformIO
pio run

# Flash na ESP32
pio run -t upload

# Monitor serial
pio device monitor
