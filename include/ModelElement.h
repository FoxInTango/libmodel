#ifndef _MODEL_ELEMENT_H_
#define _MODEL_ELEMENT_H_
#include <libcpp/libcpp.h>

namespace foxintango {
class ModelElementIMPL;
class foxintangoAPI ModelElement {
protected:
    ModelElementIMPL* impl;
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
    MET_MAP,
    MET_STRING,
    MET_MODEL
} MODEL_ELEMENT_TYPE;
public:
    ModelElement();
    virtual ~ModelElement();
public:
    virtual MODEL_ELEMENT_TYPE type();
    virtual const char* typeString();
public:
    virtual bool toBool();
    virtual char toChar();
public:
    virtual bool operator == (const MODEL_ELEMENT_TYPE& type);

    virtual ModelElement* operator [](const int&  index);
    virtual ModelElement* operator [](const char* name);

    virtual void operator = (const char* content);
};
}
#endif
