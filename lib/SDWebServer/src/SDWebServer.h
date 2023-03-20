#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <SD.h>
#include <MimeTypes.h>

namespace SDWebServer
{
    extern WebServer *g_pWebServer;

    void SetUpWifi(const char *ssid, const char *password);
    String GetContentType(String path);
}