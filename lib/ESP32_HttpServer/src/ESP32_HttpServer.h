#pragma once
#include <Arduino.h>
#include <WiFi.h>

namespace ESP32_HttpServer
{
    void SetUpWifi(const char *ssid, const char *password);
    String GetContentType(String filename);
}