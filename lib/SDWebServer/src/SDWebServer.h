#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

namespace SDWebServer
{
    WebServer *g_pWebServer = nullptr;

    void SetUpWifi(const char *ssid, const char *password);
    String GetContentType(String filename);
}