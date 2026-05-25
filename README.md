# Embedded Sensor Node - ESP32

[![PlatformIO](https://img.shields.io/badge/PlatformIO-ESP32-blue)](https://platformio.org/)
[![FreeRTOS](https://img.shields.io/badge/RTOS-FreeRTOS-green)](https://freertos.org/)

## Descrição

Projeto de firmware embarcado para ESP32 utilizando ESP-IDF e FreeRTOS. Implementa arquitetura multitarefa com comunicação entre tasks via Queue (producer/consumer).

## Roadmap
- ✅ **Multitarefa** com FreeRTOS 
- ✅ **Comunicação entre tasks** via Queue
- ✅ **Estrutura de dados** compartilhada 
- ✅ **Tratamento de erros** na criação de tasks e queue
- ✅ **Simulação de dados** do sensor com variação realista
- ✅ **Modularização** 
- [ ] Event manager
- [ ] Wi-Fi state machine
- [ ] MQTT integration
- [ ] OLED display
- [ ] OTA updates
- [ ] PCB design

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
