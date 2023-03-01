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
#include "SDWebServer.h"

using namespace SDWebServer;

void handleUserRequet();
bool handleFileRead(String path);

void setup()
{
  // 初始化硬件串口并设置波特率为9600
  Serial.begin(115200);
  SetUpWifi("hjc_esp32", "123456789");
  g_pWebServer = new WebServer(80);
  if (!SD.begin())
  {
    Serial.println("initialization failed!");
  }

  g_pWebServer->onNotFound(handleUserRequet); // 告知系统如何处理用户请求

  g_pWebServer->begin(); // 启动网站服务
  Serial.println("HTTP server started");
}

void loop()
{
  g_pWebServer->handleClient();
}

bool handleFileRead(String path)
{
  Serial.println("处理文件读写");

  // 处理浏览器HTTP访问
  if (path.endsWith("/"))
  {                       // 如果访问地址以"/"为结尾
    path = "/index.html"; // 则将访问地址修改为/index.html便于SPIFFS访问
  }

  if (!path.startsWith("/"))
  {
    path = "/" + path;
  }

  String contentType = GetContentType(path); // 获取文件类型

  if (SD.exists(path))
  {                                              // 如果访问的文件可以在SPIFFS中找到
    File file = SD.open(path, "r");              // 则尝试打开该文件
    g_pWebServer->streamFile(file, contentType); // 并且将该文件返回给浏览器
    file.close();                                // 并且关闭文件
    return true;                                 // 返回true
  }
  return false; // 如果文件未找到，则返回false
}

// 处理用户浏览器的HTTP访问
void handleUserRequet()
{
  Serial.println("处理请求");
  // 获取用户请求网址信息
  String webAddress = g_pWebServer->uri();

  // 通过handleFileRead函数处处理用户访问
  bool fileReadOK = handleFileRead(webAddress);

  // 如果在SPIFFS无法找到用户访问的资源，则回复404 (Not Found)
  if (!fileReadOK)
  {
    g_pWebServer->send(404, "text/plain", "404 Not Found");
  }
}
