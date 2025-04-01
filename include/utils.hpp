#ifndef UTILS_HPP
#define UTILS_HPP
#pragma once
#ifdef __unix__
#define TARGET_OS_UNIX
#elif defined(__WIN32) || defined(WIN32)
#define TARGET_OS_WINDOWS
#endif // OS separator quickfix ;)
#endif // UTILS_HPP
