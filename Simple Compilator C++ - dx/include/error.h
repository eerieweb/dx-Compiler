#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <stdexcept>

class CompileError : public std::runtime_error {
public:
    CompileError(const std::string& message) : std::runtime_error(message) {}
};

#endif // ERROR_H
