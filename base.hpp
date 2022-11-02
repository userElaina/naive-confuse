#pragma once

#include <iostream>
// #include <cstdio>
#include <cstring>
// #include <stdbool.h>

typedef unsigned char B;

inline std::string short_os_name(){
#if defined(__WINDOWS_) || defined(_WIN32)
    return "win";
#else
    return "linux";
#endif
}

inline void throws(const char *s) {
    throw std::runtime_error(std::string(s));
}

inline int endswith(std::string s, std::string sub) {
    return s.rfind(sub) < s.length() && s.rfind(sub) == (s.length() - sub.length());
}
