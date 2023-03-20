#pragma once
#ifndef MIMETYPES_H_
#define MIMETYPES_H_
#include <map>
#include <Arduino.h>

namespace SDWebServer
{
  class MimeTypes
  {
  public:
    static String GetType(String path);

  private:
    static std::map<String, String> _Types;
  };
}
#endif
