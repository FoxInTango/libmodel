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
namespaceBegin(foxintango)

class ModelElementIMPL;

class foxintangoAPI ModelElement {
protected:
    ModelElementIMPL* impl;
public:
typedef enum _MODEL_ELEMENT_TYPE
{
    MET_UNKNOWN,
    MET_NULL,    // nullptr
    MET_VOID,    // void
    MET_ADDRESS, // pointer 
    MET_BOOL,    // bool
    MET_CHAR,    // char
    MET_CHAR_U,  // unsigned char
    MET_SHORT,   // short
    MET_SHORT_U, // unsigned char
    MET_INT,     // int
    MET_INT_U,   // unsigned int
    MET_LONG,    // long
    MET_LONG_U,  // unsigned long
    MET_FLOAT,   // float
    MET_DOUBLE,  // double
    MET_ARRAY,   // array
    MET_MAP,     // map
    MET_STRING,  // string
    MET_MODEL    // model
}MODEL_ELEMENT_TYPE;

typedef enum _MODEL_ELEMENT_STATUS
{
    MES_OK
}MODEL_ELEMENT_STATUS;

protected:
    ModelElement();
    void setType(const MODEL_ELEMENT_TYPE& t);
public:
    /** NOTE
     * */
    ModelElement(const MODEL_ELEMENT_TYPE& t); // 
    ModelElement(const ModelElement& v);       // copy
    ModelElement(const bool& v);
    ModelElement(const char& v);
    virtual ~ModelElement();
public:
    virtual MODEL_ELEMENT_TYPE type();
    virtual const char* typeString();
public:
    /** conversion
     * t:target
     * */
    bool as(bool& t);
    bool as(char& t);
    bool as(unsigned char& t);
    bool as(short& t);
    bool as(unsigned short& t);
    bool as(int& t);
    bool as(unsigned int& t);
    bool as(long& t);
    bool as(unsigned long& t);
    bool as(float& t);
    bool as(double& t);
    bool as(char* t);
    bool as(void* t);

    /** conversion operator
     * */
    operator bool();
    operator char();
    operator unsigned char();
    operator short();
    operator unsigned short();
    operator int();
    operator unsigned int();
    operator long();
    operator unsigned long();
    operator float();
    operator double();
    operator char*();
    operator void*();
    operator MODEL_ELEMENT_TYPE();
public:
    virtual ModelElement* subelementAt(const char* key);
    virtual ModelElement* subelementAt(const unsigned int& index);
public:
    virtual ModelElement& operator = (const bool& v);
    virtual ModelElement& operator = (const char& v);
    virtual ModelElement& operator = (const unsigned char& v);
    ModelElement& operator = (const short& v);
    ModelElement& operator = (const unsigned short& v);
    ModelElement& operator = (const int& v);
    ModelElement& operator = (const unsigned int& v);
    ModelElement& operator = (const long& v);
    ModelElement& operator = (const unsigned long& v);
    ModelElement& operator = (const float& v);
    ModelElement& operator = (const double& v);
    ModelElement& operator = (const char* v);
    ModelElement& operator = (const void* v);
    ModelElement& operator = (const ModelElement& e);

    virtual bool operator == (const MODEL_ELEMENT_TYPE& type);

    virtual bool operator == (const ModelElement* e);
    virtual bool operator == (const ModelElement& e);

    bool operator == (const char& v);
    bool operator == (const unsigned char& v);
    bool operator == (const short& v);
    bool operator == (const unsigned short& v);
    bool operator == (const int& v);
    bool operator == (const unsigned int& v);
    bool operator == (const float& v);
    bool operator == (const double& v);
    bool operator == (const char* v);
    bool operator == (const void* v);

    ModelElement* operator [](const int&  index);
    ModelElement* operator [](const char* name);
};

bool operator << (bool& v,ModelElement& e);
bool operator >> (ModelElement& e,bool& v);

bool operator << (char& v,ModelElement& e);
bool operator >> (ModelElement& e,char& v);

bool operator << (unsigned char& v,ModelElement& e);
bool operator >> (ModelElement& e,unsigned char& v);

bool operator << (short& v,ModelElement& e);
bool operator >> (ModelElement& e,short& v);

bool operator << (unsigned short& v,ModelElement& e);
bool operator >> (ModelElement& e,unsigned short& v);

bool operator << (int& v,ModelElement& e);
bool operator >> (ModelElement& e,int& v);

bool operator << (unsigned int& v,ModelElement& e);
bool operator >> (ModelElement& e,unsigned int& v);

bool operator << (long& v,ModelElement& e);
bool operator >> (ModelElement& e,long& v);

bool operator << (unsigned long& v,ModelElement& e);
bool operator >> (ModelElement& e,unsigned long& v);

bool operator << (float& v,ModelElement& e);
bool operator >> (ModelElement& e,float& v);

bool operator << (double& v,ModelElement& e);
bool operator >> (ModelElement& e,double& v);

bool operator << (char* v,ModelElement& e);
bool operator >> (ModelElement& e,char* v);

bool operator << (void* v,ModelElement& e);
bool operator >> (ModelElement& e,void* v);

namespaceEnd
#endif
