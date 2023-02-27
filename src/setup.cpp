#include "setup.h"
#include <Arduino.h>
#include <WiFi.h>
#include <SPI.h>
#include <SD.h>

#define AP_ssid "hjc_esp32" // 这里改成你的设备当前环境下接入点名字
#define password "12345678" // 这里改成你的设备当前环境下接入点密码

void SetUpWifi(void)
{
    WiFi.mode(WIFI_AP);
    // 启动接入点模式，并设置账号和密码
    Serial.print("设置接入点中 ... ");
    // 启动校验式网络（需要输入账号密码的网络）,通道为3，wifi隐藏，最大连接数=4
    WiFi.softAP(AP_ssid, password, 3);

    Serial.println("");            // 通过串口监视器输出信息
    Serial.print("当前工作模式:"); // 告知用户设备当前工作模式
    Serial.println(WiFi.getMode());
    Serial.print("接入点名字:");
    Serial.println(AP_ssid); // 告知用户建立的接入点WiFi名
    Serial.print("接入点密码:");
    Serial.println(password); // 告知用户建立的接入点WiFi密码
}