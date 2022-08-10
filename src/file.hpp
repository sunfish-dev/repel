#pragma once
#include <string>
#include <fstream>

#ifndef __has_include
  static_assert(false, "__has_include not supported");
#else
#  if __cplusplus >= 201703L && __has_include(<filesystem>)
#    include <filesystem>
     namespace fs = std::filesystem;
#  elif __has_include(<experimental/filesystem>)
#    include <experimental/filesystem>
     namespace fs = std::experimental::filesystem;
#  elif __has_include(<boost/filesystem.hpp>)
#    include <boost/filesystem.hpp>
     namespace fs = boost::filesystem;
#  endif
#endif

std::string ReadFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    std::string output, content;
    while (std::getline(file, output)) content+=output+'\n';
    content.pop_back();
    file.close();
    return content;
}

void WriteFile(const std::string& filePath, const std::string& text)
{
    std::ofstream file(filePath);
    file << text;
    file.close();
}