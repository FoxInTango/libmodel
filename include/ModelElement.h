#ifndef _MODEL_ELEMENT_H_
#define _MODEL_ELEMENT_H_
#include <libcpp/libcpp.h>

namespace foxintango {
class foxintangoAPI ModelElement {
public:
typedef enum _MODEL_ELEMENT_TYPE 
{
    MET_NULL,    // nullptr
    MET_VOID,    // void
    MET_BOOL,    // bool
    MET_CHAR,    // char
    MET_CHAR_U,  // unsigned char
    MET_SHORT,   // short
    MET_SHORT_U, // unsigned char
    MET_INT,
    MET_INT_U,
    MET_LONG,
    MET_DOUBLE,
    MET_ARRAY,
    MET_MAP
} MODEL_ELEMENT_TYPE;
public:
    ModelElement();
    virtual ~ModelElement();
public:
    virtual bool toBool();
    virtual char toChar()
};
}
#endif
