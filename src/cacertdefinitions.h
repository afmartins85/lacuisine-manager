#ifndef CACERTDEFINITIONS_H
#define CACERTDEFINITIONS_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
// define something for Windows (32-bit and 64-bit, this part is common)
#ifdef _WIN64
// define something for Windows (64-bit only)
#else
// define something for Windows (32-bit only)
#endif
#elif __APPLE__
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#elif TARGET_OS_IPHONE
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
char clientPEM[] = {"/usr/local/opt/ca-certificates/lacuisine/client.pem"};
char cacert[] = {"/usr/local/opt/ca-certificates/lacuisine/cacert.pem"};
char passwd[] = {"ZIWw3HND$yG6naizADpF"};
#else
#error "Unknown Apple platform"
#endif
#elif __linux__
// linux
char clientPEM[] = {"/usr/local/share/ca-certificates/lacuisine/client.pem"};
char cacert[] = {"/usr/local/share/ca-certificates/lacuisine/cacert.pem"};
char passwd[] = {"ZIWw3HND$yG6naizADpF"};
#elif __unix__  // all unices not caught above
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#error "Unknown compiler"
#endif

#endif  // CACERTDEFINITIONS_H
