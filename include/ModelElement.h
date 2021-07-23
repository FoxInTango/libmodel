#ifndef _MODEL_ELEMENT_H_
#define _MODEL_ELEMENT_H_

#include <libcpp/libcpp.h>

/** ModelElement
 *  native
 *  {
 *      value
 *  }
 *  array
 *  {elementA,elementB,elementC}
 *  map
 *  {
 *      name:element
 *  }
 * */
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
    MET_ADDRESS, // 
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

typedef enum _MODEL_ELEMENT_STATUS
{
    MES_OK
}MODEL_ELEMENT_STATUS;

protected:
    ModelElement();
public:
    ModelElement(const char* string);
    virtual ~ModelElement();
public:
    virtual MODEL_ELEMENT_TYPE type();
    virtual const char* typeString();
public:
    virtual bool           toBool();
    virtual char           toChar();
    virtual unsigned char  toCharU();
    virtual short          toShort();
    virtual unsigned short toShortU();
    virtual int            toInt();
    virtual unsigned       toIntU();
    virtual long           toLong();
    virtual double         toDouble();
    virtual char*          toString();
public:
    virtual ModelElement* subelementAt(const char* key);
    virtual ModelElement* subelementAt(const unsigned int& index);
public:
    virtual void operator = (const char* content);
    
    virtual bool operator == (const MODEL_ELEMENT_TYPE& type);

    virtual bool operator == (const ModelElement* e);
    virtual bool operator == (const ModelElement& e);

    virtual void operator << (const ModelElement& e);
    
    virtual ModelElement* operator [](const int&  index);
    virtual ModelElement* operator [](const char* name);
};
}
#endif
