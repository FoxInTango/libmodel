#ifndef _MODEL_NUMBER_H_
#define _MODEL_NUMBER_H_
#include <libcpp/libcpp.h>

namespaceBegin(foxintango)
enum MODEL_NUMBER_STRING_FORMAT {};
enum MODEL_NUMBER_STRING_TYPE {};

struct MODEL_NUMBER_STRING_STRUCT {
    MODEL_NUMBER_STRING_FORMAT format;
    MODEL_NUMBER_STRING_TYPE type;
};
namespaceEnd

foxintango::MODEL_NUMBER_STRING_STRUCT number_string_info(const char* s);
#endif
