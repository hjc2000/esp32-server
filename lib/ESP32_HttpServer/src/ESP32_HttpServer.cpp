#include "ESP32_HttpServer.h"

namespace ESP32_HttpServer
{
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

    String GetContentType(String filename)
    {
        if (filename.endsWith(".html"))
            return "text/html";
        else if (filename.endsWith(".css"))
            return "text/css";
        else if (filename.endsWith(".js"))
            return "application/javascript";
        else if (filename.endsWith(".png"))
            return "image/png";
        else if (filename.endsWith(".gif"))
            return "image/gif";
        else if (filename.endsWith(".jpg"))
            return "image/jpeg";
        else if (filename.endsWith(".ico"))
            return "image/x-icon";
        else if (filename.endsWith(".xml"))
            return "text/xml";
        else if (filename.endsWith(".pdf"))
            return "application/x-pdf";
        else if (filename.endsWith(".zip"))
            return "application/x-zip";
        else if (filename.endsWith(".gz"))
            return "application/x-gzip";
        return "text/plain";
    }
}