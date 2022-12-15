/*
 * libmodel
 *
 * Copyright (C) 2021 FoxInTango <foxintango@yeah.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
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
EXTERN_C_BEGIN
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
    MET_STRING,  // string
    MET_ARRAY,   // array
    MET_KV,      // KV Pair
    MET_MAP      // map
}MODEL_ELEMENT_TYPE;

typedef enum _MODEL_ELEMENT_STATUS //类型转换状态
{
    MES_OK
}MODEL_ELEMENT_STATUS;

protected:
    ModelElement();
    const MODEL_ELEMENT_TYPE setType(const MODEL_ELEMENT_TYPE& t);
public:
    /** NOTE
     * */
    ModelElement(const MODEL_ELEMENT_TYPE& t); // 
    ModelElement(const ModelElement& e);       // copy
    ModelElement(const ModelElement* e);
    ModelElement(const char* name,const ModelElement& e);       // copy
    ModelElement(const char* name,const ModelElement* e);
    ModelElement(const bool& t);
    ModelElement(const char& t);
    ModelElement(const unsigned char& t);
    ModelElement(const short& t);
    ModelElement(const unsigned short& t);
    ModelElement(const int& t);
    ModelElement(const unsigned int& t);
    ModelElement(const long& t);
    ModelElement(const unsigned long& t);
    ModelElement(const float& t);
    ModelElement(const double& t);
    ModelElement(const char* t);
    ModelElement(const void* t);
    virtual ~ModelElement();
public:
    virtual MODEL_ELEMENT_TYPE type() const;
    virtual const char* typeString();
public:
    /** conversion
     * t:target
     * */
    bool as(bool& t)           const;
    bool as(char& t)           const;
    bool as(unsigned char& t)  const;
    bool as(short& t)          const;
    bool as(unsigned short& t) const;
    bool as(int& t)            const;
    bool as(unsigned int& t)   const;
    bool as(long& t)           const;
    bool as(unsigned long& t)  const;
    bool as(float& t)          const;
    bool as(double& t)         const;
    bool as(char** t)          const;
    bool as(void** t)          const;

    /** conversion
     * t:target
     * */
    bool accept(bool& v);
    bool accept(char& v);
    bool accept(unsigned char& v);
    bool accept(short& v);
    bool accept(unsigned short& v);
    bool accept(int& v);
    bool accept(unsigned int& v);
    bool accept(long& v);
    bool accept(unsigned long& v);
    bool accept(float& v);
    bool accept(double& v);
    bool accept(char* v);
    bool accept(void* v);
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
    ModelElement* super();
    ModelElement* prev();
    ModelElement* next();
public:
    virtual void echo(const unsigned int& offset);
public:
    virtual unsigned int appendSubelement(const ModelElement* e);
    virtual unsigned int insertSubelement(const ModelElement* e,const char* name);
    virtual unsigned int removeSubelement(const ModelElement* e);
    virtual unsigned int removeSubelement(const char* name);
    virtual unsigned int removeSubelement(const unsigned int& index);
    virtual unsigned int subelementCount();
    virtual ModelElement* subelementAt(const char* key) const ;
    virtual ModelElement* subelementAt(const unsigned int& index) const ;
public:
    virtual ModelElement& operator = (const bool& v);
    virtual ModelElement& operator = (const char& v);
    virtual ModelElement& operator = (const unsigned char& v);
    virtual ModelElement& operator = (const short& v);
    virtual ModelElement& operator = (const unsigned short& v);
    virtual ModelElement& operator = (const int& v);
    virtual ModelElement& operator = (const unsigned int& v);
    virtual ModelElement& operator = (const long& v);
    virtual ModelElement& operator = (const unsigned long& v);
    virtual ModelElement& operator = (const float& v);
    virtual ModelElement& operator = (const double& v);
    virtual ModelElement& operator = (const char* v);
    virtual ModelElement& operator = (const void* v);
    virtual ModelElement& operator = (const ModelElement& e);

    virtual bool operator == (const MODEL_ELEMENT_TYPE& type) const;

    virtual bool operator == (const ModelElement* e) const;
    virtual bool operator == (const ModelElement& e) const;

    virtual bool operator == (const char& v) const;
    virtual bool operator == (const unsigned char& v) const;
    virtual bool operator == (const short& v) const;
    virtual bool operator == (const unsigned short& v) const;
    virtual bool operator == (const int& v) const;
    virtual bool operator == (const unsigned int& v) const;
    virtual bool operator == (const float& v) const;
    virtual bool operator == (const double& v) const;
    virtual bool operator == (const char* v) const;
    virtual bool operator == (const void* v) const;

    const ModelElement* operator [](const int&  index) const ;
    const ModelElement* operator [](const char* name)  const ;
};

typedef ModelElement ME;

namespaceEnd
EXTERN_C_END

bool foxintangoAPI operator << (foxintango::ModelElement& e,bool& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,char& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,unsigned char& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,short& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,unsigned short& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,int& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,unsigned int& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,long& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,unsigned long& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,float& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,double& v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,char* v);
bool foxintangoAPI operator << (foxintango::ModelElement& e,void* v);

bool foxintangoAPI operator >> (foxintango::ModelElement& e,bool& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,char& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,unsigned char& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,short& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,unsigned short& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,int& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,unsigned int& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,long& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,unsigned long& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,float& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,double& v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,char** v);
bool foxintangoAPI operator >> (foxintango::ModelElement& e,void** v);

bool foxintangoAPI operator >> (bool& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (char& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (unsigned char& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (short& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (unsigned short& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (int& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (unsigned int& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (long& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (unsigned long& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (float& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (double& v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (char* v,foxintango::ModelElement& e);
bool foxintangoAPI operator >> (void* v,foxintango::ModelElement& e);

bool foxintangoAPI operator << (bool& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (char& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (unsigned char& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (short& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (unsigned short& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (int& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (unsigned int& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (long& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (unsigned long& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (float& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (double& v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (char** v,foxintango::ModelElement& e);
bool foxintangoAPI operator << (void** v,foxintango::ModelElement& e);

bool foxintangoAPI operator == (const foxintango::ModelElement::MODEL_ELEMENT_TYPE& type,const foxintango::ModelElement);
bool foxintangoAPI operator == (const char& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const unsigned char& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const short& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const unsigned short& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const int& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const unsigned int& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const float& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const double& v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const char* v,const foxintango::ModelElement);
bool foxintangoAPI operator == (const void* v,const foxintango::ModelElement);

#endif
