#ifndef MARATHON_LIB_HPP
#define MARATHON_LIB_HPP

#ifdef _WIN32
    #ifdef MARATHON_LIB_EXPORT
        #define MARATHON_LIB_API __declspec(dllexport)
    #else
        #define MARATHON_LIB_API __declspec(dllimport)
    #endif
#else
    #define MARATHON_LIB_API
#endif


MARATHON_LIB_API void StartMarathon();

#endif
