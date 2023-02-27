/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-25
 *
 * @copyright Copyright (c) 2023
 * C main 函数在：
 * C:\Users\huang\.platformio\packages\framework-arduinoespressif32\cores\esp32\main.cpp
 */

#include <Arduino.h>
#include <WiFi.h>
#include <SPI.h>
#include <SD.h>
#include "setup.h"

void print(void *param)
{
  while (1)
  {
    delay(1000);
    Serial.println("hello world");
  }
}

void setup()
{
  Serial.begin(115200);
  xTaskCreate(print, "print", 4600, NULL, 1, NULL);
  SetUpWifi();
}

void loop()
{
  vTaskDelete(nullptr);
}