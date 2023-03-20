#include "SDWebServer.h"

namespace SDWebServer
{
    WebServer *g_pWebServer = nullptr;

    void SetUpWifi(const char *ssid, const char *password)
    {
        WiFi.mode(WIFI_AP);
        // 启动接入点模式，并设置账号和密码
        Serial.print("设置接入点中 ... ");
        // 启动校验式网络（需要输入账号密码的网络）,通道为3，wifi隐藏，最大连接数=4
        WiFi.softAP(ssid, password, 3);

        Serial.println("");            // 通过串口监视器输出信息
        Serial.print("当前工作模式:"); // 告知用户设备当前工作模式
        Serial.println(WiFi.getMode());
    }

    String GetContentType(String path)
    {
        return MimeTypes::GetType(path);
    }
}