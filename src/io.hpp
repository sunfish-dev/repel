#pragma once
#include <iostream>

template <typename T>
void Print(const T& t) 
{
    std::cout << t;
}
template<typename T, typename... Args>
void Print(const T& t, Args... args)
{
    std::cout << t;
    Print(args...);
}

template<typename T, typename... Args>
void PrintLine(const T& t, Args... args) 
{
    Print(t, args...);
    std::cout << '\n';
}

template <typename T>
void PrintLines(const T& t) 
{
    std::cout << t << '\n';
}

template<typename T, typename... Args>
void PrintLines(const T& t, Args... args)
{
    std::cout << t << '\n';
    PrintLines(args...);
}

template <typename T>
void Error(const T& t) 
{
    std::cerr << t;
}

template<typename T, typename... Args>
void Error(const T& t, Args... args)
{
    std::cerr << t;
    Error(args...);
}

template<typename T>
void Crash(const int& code, const T& t)
{
    std::cerr << t;
    exit(code);
}

template<typename T, typename... Args>
void Crash(const int& code, const T& t, Args... args)
{
    std::cerr << t;
    Error(args...);
    exit(code);
}