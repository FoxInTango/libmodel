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
#include "ModelElement.h"
#include <libstring/libstring.h>
#include <libcpp/libcpp.h>
using namespace foxintango;
#include <cstring>
/*
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
*/
/** MOVE TO libstring BEGIN */
#define c0 '0'
#define c1 '1'
#define c2 '2'
#define c3 '3'
#define c4 '4'
#define c5 '5'
#define c6 '6'
#define c7 '7'
#define c8 '8'
#define c9 '9'
#define cd '.'

/** NOTE :
 *CONVERSITION
 *INSERT & APPEND
 *BUFFERING
 * */
static const char* MET_STRING_ARRAY[] = 
{
    "MET_UNKNOWN",
    "MET_NULL",
    "MET_VOID",
    "MET_ADDRESS",
    "MET_BOOL",
    "MET_CHAR",
    "MET_CHAR_U",
    "MET_SHORT",
    "MET_SHORT_U",
    "MET_INT",
    "MET_INT_U",
    "MET_LONG",
    "MET_LONG_U",
    "MET_FLOAT",
    "MET_DOUBLE",
    "MET_STRING",
    "MET_ARRAY",
    "MET_KV",
    "MET_MAP"
}; 
/** 数值型判断 需要进一步细化 
 * Ox000002
 * 0.1f
 *
 * */
inline bool is_number_string (const char* v) {
    Size l = String(v).length();

    for(Size i = 0;i < l;i ++) {
        if(v[i] != c0 && 
           v[i] != c1 && 
           v[i] != c2 && 
           v[i] != c3 && 
           v[i] != c4 && 
           v[i] != c5 && 
           v[i] != c6 &&
           v[i] != c7 &&
           v[i] != c8 &&
           v[i] != c9 &&
           v[i] != cd)
           return false;
    }
    return true;
}
/** MOVE TO libstring END   */

inline const void echo_offset_string(const unsigned int& offset) {
}
namespace foxintango {
/**
 * NOTE:
 * element TO char* 
 * char*   TO element
 * */
class foxintangoAPI ModelElementIMPL {
public:
    Index  index;
    //ModelElement* super;
    //Array<ModelElement*> supers; // Array 导致内存访问出错 见 TODO.md
public:
    ModelElement::MODEL_ELEMENT_TYPE   type;
    ModelElement::MODEL_ELEMENT_STATUS status;
public:
    ModelElementIMPL(){
        //super  = 0;
        index  = 0;
        type   = ModelElement::MET_UNKNOWN;
        status = ModelElement::MES_OK;
    }
   
    virtual ~ModelElementIMPL(){
        /** TODO 
         *  1,容器类模型元素析构过程中，检查子元素引用数，如无其他引用，销毁该元素
         *  2,本元素析构时，调用引用者子元素析构事件处理函数
         *  附：添加子元素事件处理成员函数
         *      添加元素克隆函数
         */
    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char** t)         {return false;}
    virtual bool equal(const void** t)         {return false;}
public:
    virtual unsigned int  appendSubelement(const ModelElement* e)                  { return 0; }
    virtual unsigned int  insertSubelement(const ModelElement* e,const char* name) { return 0; }
    virtual unsigned int  removeSubelement(const ModelElement* e)                  { return 0; }
    virtual unsigned int  removeSubelement(const char* name)                       { return 0; }
    virtual unsigned int  removeSubelement(const unsigned int& index)              { return 0; }
    virtual unsigned int  subelementCount()                                        { return 0; }
    virtual ModelElement* subelementAt(const char* key)                            { return 0; }
    virtual ModelElement* subelementAt(const unsigned int& index)                  { return 0; }
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementUNKNOWN :public ModelElementIMPL {
public:
    ModelElementUNKNOWN() {
        type   = ModelElement::MET_UNKNOWN;
        status = ModelElement::MES_OK;
    }
    ~ModelElementUNKNOWN() {
    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementNULL :public ModelElementIMPL {
public:
    ModelElementNULL() {
       type   = ModelElement::MET_NULL;
       status = ModelElement::MES_OK;
    }
   
   ~ModelElementNULL() {
   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return 0 == t ? true : false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementVOID :public ModelElementIMPL {
public:
    ModelElementVOID() {
        type   = ModelElement::MET_VOID;
        status = ModelElement::MES_OK;
    }
   
   ~ModelElementVOID() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

ModelElementVOID MODEL_ELEMENT_VOID_INSTANCE_DEFAULT;

class ModelElementADDRESS :public ModelElementIMPL {
public:
    void* value;
public:
    ModelElementADDRESS() {
        type   = ModelElement::MET_ADDRESS;
        status = ModelElement::MES_OK;
    }
   
   ~ModelElementADDRESS() {
   
   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const { *t = value;return true; }
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          { value = const_cast<void*>(t);return true; }
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          { return value == t ? true : false; }
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementBOOL :public ModelElementIMPL {
public:
    bool value;
public:
    ModelElementBOOL() {
        type   = ModelElement::MET_BOOL;
        status = ModelElement::MES_OK;
    }
   
   ~ModelElementBOOL() { 
   }
public:
    virtual bool as(bool& t)           const {t = value;return true;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {value = t;return true;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return value == t ? true : false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementCHAR :public ModelElementIMPL {
public:
    char value;
public:
    ModelElementCHAR() {
        type   = ModelElement::MET_CHAR;
        status = ModelElement::MES_OK;
    }

   ~ModelElementCHAR() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {t = value;return true;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {value = t;return true;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return value == t ? true : false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementCHAR_U :public ModelElementIMPL {
public:
    unsigned char value;
public:
    ModelElementCHAR_U() {
        type   = ModelElement::MET_CHAR_U;
        status = ModelElement::MES_OK;
    }

   ~ModelElementCHAR_U() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {t = value;return true;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {value = t;return true;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return value == t ? true : false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementSHORT :public ModelElementIMPL {
public:
    short value;
public:
    ModelElementSHORT() {
        type   = ModelElement::MET_SHORT;
        status = ModelElement::MES_OK;
    }

   ~ModelElementSHORT() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {t = value;return true;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {value = t;return true;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return value == t ? true : false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementSHORT_U :public ModelElementIMPL {
public:
    unsigned short value;
public:
    ModelElementSHORT_U() {
        type   = ModelElement::MET_SHORT_U;
        status = ModelElement::MES_OK;
    }

   ~ModelElementSHORT_U() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {t = value;return true;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){value = t;return true;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)           {return false;}
    virtual bool equal(const char& t)           {return false;}
    virtual bool equal(const unsigned char& t)  {return false;}
    virtual bool equal(const short& t)          {return false;}
    virtual bool equal(const unsigned short& t) {return value == t ? true : false;}
    virtual bool equal(const int& t)            {return false;}
    virtual bool equal(const unsigned int& t)   {return false;}
    virtual bool equal(const long& t)           {return false;}
    virtual bool equal(const unsigned long& t)  {return false;}
    virtual bool equal(const float& t)          {return false;}
    virtual bool equal(const double& t)         {return false;}
    virtual bool equal(const char* t)           {return false;}
    virtual bool equal(const void* t)           {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementINT :public ModelElementIMPL  {
public:
    int value;
public:
    ModelElementINT() {
        type   = ModelElement::MET_INT;
        status = ModelElement::MES_OK;
    }

   ~ModelElementINT() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {t = value;return true;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {value = t;return true;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return value == t ? true : false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementINT_U :public ModelElementIMPL {
public:
    unsigned int value;
public:
    ModelElementINT_U() {
        type   = ModelElement::MET_INT_U;
        status = ModelElement::MES_OK;
    }

   ~ModelElementINT_U() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {t = value;return true;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {value = t;return true;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return value == t ? true : false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementLONG :public ModelElementIMPL {
public:
    long value;
public:
    ModelElementLONG() {
        type   = ModelElement::MET_LONG;
        status = ModelElement::MES_OK;
    }

   ~ModelElementLONG() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {t = value;return true; }
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {value = t;return true;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return value == t ? true : false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementLONG_U :public ModelElementIMPL {
public:
    unsigned long value;
public:
    ModelElementLONG_U() {
        type   = ModelElement::MET_LONG_U;
        status = ModelElement::MES_OK;
    }
    
    ~ModelElementLONG_U() {

    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {t = value;return true;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {value = t;return true;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return value == t ? true : false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementFLOAT :public ModelElementIMPL {
public:
    float value;
public:
    ModelElementFLOAT() {
        type   = ModelElement::MET_FLOAT;
        status = ModelElement::MES_OK;
    }
    
    ~ModelElementFLOAT() {

    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {t = value;return true;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {value = t;return true;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return value == t ? true : false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    /**
     * 精度 及对齐
     * */
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementDOUBLE :public ModelElementIMPL {
public:
    double value;
public:
    ModelElementDOUBLE() {
        type   = ModelElement::MET_DOUBLE;
        status = ModelElement::MES_OK;
    }

   ~ModelElementDOUBLE() {

   }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {t = value;return true;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {value = t;return true;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return value == t ? true : false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementSTRING :public ModelElementIMPL {
public:
    String value;
public:
    ModelElementSTRING() {
        type   = ModelElement::MET_STRING;
        status = ModelElement::MES_OK;
    }

    ~ModelElementSTRING() {
    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return value.as(t);}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          { value = t;  }/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return value == t ? true : false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementARRAY :public ModelElementIMPL {
public:
    Array<ModelElement*> subelements;
public:
    ModelElementARRAY() {
        type   = ModelElement::MET_ARRAY;
        status = ModelElement::MES_OK;
    }

    ~ModelElementARRAY() {
    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:                                                                            /**IMPL  **/
    virtual unsigned int  appendSubelement(const ModelElement* e)                  { subelements.append(const_cast<ModelElement*>(e)); return subelements.size(); }
    //virtual unsigned int  insertSubelement(const ModelElement* e,const char* name) { return 0; }
    virtual unsigned int  removeSubelement(const ModelElement* e)                  { Index i = 0;while(i != subelements.size()) {if(subelements[i] == e) subelements.remove(i);i ++;}
                                                                                     return subelements.size(); 
                                                                                   }
    //virtual unsigned int  removeSubelement(const char* name)                       { return 0; }
    virtual unsigned int  removeSubelement(const int& index)                       { subelements.remove(index); return subelements.size(); }
    virtual unsigned int  subelementCount()                                        { return subelements.size(); }
    //virtual ModelElement* subelementAt(const char* key)           const            { return 0; }
    virtual ModelElement* subelementAt(const unsigned int& index)            { return index < subelements.size() ? subelements.at(index) : 0; }
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementKV : public ModelElementIMPL {
public:
    String  name;
    ModelElement* element;
public:
    ModelElementKV(){
        type   = ModelElement::MET_KV;
        status = ModelElement::MES_OK;
    }

    ~ModelElementKV(){
    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:
    virtual void echo(const unsigned int& offset) { }
};

class ModelElementMAP :public ModelElementIMPL {
public:
    Map<String,ModelElement*> subelements;
public:
    ModelElementMAP() {
        type   = ModelElement::MET_MAP;
        status = ModelElement::MES_OK;
    }

    ~ModelElementMAP() {
    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
public:                                                                            /**IMPL  **/
    virtual unsigned int  appendSubelement(const ModelElement* e)                  { return 0; }
    virtual unsigned int  insertSubelement(const ModelElement* e,const char* name) { subelements.insert(name,const_cast<ModelElement*>(e));/*MAP_ECHO*/;return subelements.size(); }
    //virtual unsigned int  removeSubelement(const ModelElement* e)                  { return subelements.remove(e);}
    virtual unsigned int  removeSubelement(const char* name)                       { return subelements.remove(name); }
    //virtual unsigned int  removeSubelement(const unsigned int& index)              { }
    virtual unsigned int  subelementCount()                                        { return subelements.size(); }
    virtual ModelElement* subelementAt(const char* key)                            { return subelements.count(key) ? subelements.at(key) : 0; }
    //virtual ModelElement* subelementAt(const unsigned int& index)  const           { }
public:
    virtual void echo(const unsigned int& offset) {}
};

class ModelElementMODEL :public ModelElementIMPL {
public:
    ModelElementMODEL() {
        type   = ModelElement::MET_MAP;
        status = ModelElement::MES_OK;
    }

    ~ModelElementMODEL() {
    }
public:
    virtual bool as(bool& t)           const {return false;}
    virtual bool as(char& t)           const {return false;}
    virtual bool as(unsigned char& t)  const {return false;}
    virtual bool as(short& t)          const {return false;}
    virtual bool as(unsigned short& t) const {return false;}
    virtual bool as(int& t)            const {return false;}
    virtual bool as(unsigned int& t)   const {return false;}
    virtual bool as(long& t)           const {return false;}
    virtual bool as(unsigned long& t)  const {return false;}
    virtual bool as(float& t)          const {return false;}
    virtual bool as(double& t)         const {return false;}
    virtual bool as(char** t)          const {return false;}
    virtual bool as(void** t)          const {return false;}
public:
    virtual bool accept(const bool& t)          {return false;}
    virtual bool accept(const char& t)          {return false;}
    virtual bool accept(const unsigned char& t) {return false;}
    virtual bool accept(const short& t)         {return false;}
    virtual bool accept(const unsigned short& t){return false;}
    virtual bool accept(const int& t)           {return false;}
    virtual bool accept(const unsigned int& t)  {return false;}
    virtual bool accept(const long& t)          {return false;}
    virtual bool accept(const unsigned long& t) {return false;}
    virtual bool accept(const float& t)         {return false;}
    virtual bool accept(const double& t)        {return false;}
    virtual bool accept(const char* t)          {return false;}/** 尝试解析:NUMBER JSON XML YML...*/
    virtual bool accept(const void* t)          {return false;}
public:
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
};
}

ModelElement::ModelElement(const MODEL_ELEMENT_TYPE& t) {
    switch(t) {
    case ModelElement::MET_UNKNOWN:{ this->impl = new ModelElementUNKNOWN(); }break;
    case ModelElement::MET_NULL:   { this->impl = new ModelElementNULL();    }break;
    case ModelElement::MET_VOID:   { this->impl = new ModelElementVOID();    }break;
    case ModelElement::MET_ADDRESS:{ this->impl = new ModelElementADDRESS(); }break;
    case ModelElement::MET_BOOL:   { this->impl = new ModelElementBOOL();    }break;
    case ModelElement::MET_CHAR:   { this->impl = new ModelElementCHAR();    }break;
    case ModelElement::MET_CHAR_U: { this->impl = new ModelElementCHAR_U();  }break;
    case ModelElement::MET_SHORT:  { this->impl = new ModelElementSHORT();   }break;
    case ModelElement::MET_SHORT_U:{ this->impl = new ModelElementSHORT_U(); }break;
    case ModelElement::MET_INT:    { this->impl = new ModelElementINT();     }break;
    case ModelElement::MET_INT_U:  { this->impl = new ModelElementINT_U();   }break;
    case ModelElement::MET_LONG:   { this->impl = new ModelElementLONG();    }break;
    case ModelElement::MET_LONG_U: { this->impl = new ModelElementLONG_U();  }break;
    case ModelElement::MET_FLOAT:  { this->impl = new ModelElementFLOAT();   }break;
    case ModelElement::MET_DOUBLE: { this->impl = new ModelElementDOUBLE();  }break;
    case ModelElement::MET_ARRAY:  { this->impl = new ModelElementARRAY();   }break;
    case ModelElement::MET_MAP:    { this->impl = new ModelElementMAP();     }break;
    case ModelElement::MET_STRING: { this->impl = new ModelElementSTRING();  }break;
    //case ModelElement::MET_MAP:    { this->impl = new ModelElementMAP();   }break;
    default:break;
    }
}

ModelElement::ModelElement(const ModelElement& e) {
    switch(e.type()) {
    case ModelElement::MET_UNKNOWN:{ this->impl = new ModelElementUNKNOWN(); }break;
    case ModelElement::MET_NULL:   { this->impl = new ModelElementNULL();    }break;
    case ModelElement::MET_VOID:   { this->impl = new ModelElementVOID();    }break;
    case ModelElement::MET_ADDRESS:{ 
         ModelElementADDRESS* address = new ModelElementADDRESS(); 
         e.as(&address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_BOOL:   { 
         ModelElementBOOL* address = new ModelElementBOOL(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_CHAR:   { 
         ModelElementCHAR* address = new ModelElementCHAR(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_CHAR_U: { 
         ModelElementCHAR_U* address = new ModelElementCHAR_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_SHORT:  { 
         ModelElementSHORT* address = new ModelElementSHORT(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_SHORT_U:{ 
         ModelElementSHORT_U* address = new ModelElementSHORT_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_INT:    { 
         ModelElementINT* address = new ModelElementINT(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_INT_U:  { 
         ModelElementINT_U* address = new ModelElementINT_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_LONG:   { 
         ModelElementLONG* address = new ModelElementLONG(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_LONG_U: { 
         ModelElementLONG_U* address = new ModelElementLONG_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_FLOAT:  { 
         ModelElementFLOAT* address = new ModelElementFLOAT(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_DOUBLE: { 
         ModelElementDOUBLE* address = new ModelElementDOUBLE(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_ARRAY:  { this->impl = new ModelElementARRAY();   }break;//复制
    case ModelElement::MET_MAP:    { this->impl = new ModelElementMAP();     }break;//复制
    case ModelElement::MET_STRING: { this->impl = new ModelElementSTRING();  }break;//复制
    //case ModelElement::MET_MODEL:  { this->impl = new ModelElementMODEL();   }break;//复制
    default:break;
    }
}

ModelElement::ModelElement(const ModelElement* p) 
{
    if(!p) this->impl = new ModelElementUNKNOWN();
    const ModelElement& e = *p;
    switch(e.type()) {
    case ModelElement::MET_UNKNOWN:{ this->impl = new ModelElementUNKNOWN(); }break;
    case ModelElement::MET_NULL:   { this->impl = new ModelElementNULL();    }break;
    case ModelElement::MET_VOID:   { this->impl = new ModelElementVOID();    }break;
    case ModelElement::MET_ADDRESS:{ 
         ModelElementADDRESS* address = new ModelElementADDRESS(); 
         e.as(&address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_BOOL:   { 
         ModelElementBOOL* address = new ModelElementBOOL(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_CHAR:   { 
         ModelElementCHAR* address = new ModelElementCHAR(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_CHAR_U: { 
         ModelElementCHAR_U* address = new ModelElementCHAR_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_SHORT:  { 
         ModelElementSHORT* address = new ModelElementSHORT(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_SHORT_U:{ 
         ModelElementSHORT_U* address = new ModelElementSHORT_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_INT:    { 
         ModelElementINT* address = new ModelElementINT(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_INT_U:  { 
         ModelElementINT_U* address = new ModelElementINT_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_LONG:   { 
         ModelElementLONG* address = new ModelElementLONG(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_LONG_U: { 
         ModelElementLONG_U* address = new ModelElementLONG_U(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_FLOAT:  { 
         ModelElementFLOAT* address = new ModelElementFLOAT(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_DOUBLE: { 
         ModelElementDOUBLE* address = new ModelElementDOUBLE(); 
         e.as(address->value);
         this->impl = static_cast<ModelElementIMPL*>(address);
         }break;
    case ModelElement::MET_ARRAY:  { this->impl = new ModelElementARRAY();   }break;//复制 类型转换
    case ModelElement::MET_MAP:    { this->impl = new ModelElementMAP();     }break;//复制
    case ModelElement::MET_STRING: { this->impl = new ModelElementSTRING();  }break;//复制
    //case ModelElement::MET_MODEL:  { this->impl = new ModelElementMODEL();   }break;//复制
    default:break;
    }
}

// ElementKV
ModelElement::ModelElement(const char* name,const ModelElement& e) {

}

ModelElement::ModelElement(const char* name,const ModelElement* e) {

}

ModelElement::ModelElement(const bool& t)           { this->impl = new ModelElementBOOL;    if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const char& t)           { this->impl = new ModelElementCHAR;    if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const unsigned char& t)  { this->impl = new ModelElementCHAR_U;  if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const short& t)          { this->impl = new ModelElementSHORT;   if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const unsigned short& t) { this->impl = new ModelElementSHORT_U; if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const int& t)            { this->impl = new ModelElementINT;     if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const unsigned int& t)   { this->impl = new ModelElementINT_U;   if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const long& t)           { this->impl = new ModelElementLONG;    if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const unsigned long& t)  { this->impl = new ModelElementLONG_U;  if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const float& t)          { this->impl = new ModelElementFLOAT;   if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const double& t)         { this->impl = new ModelElementDOUBLE;  if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const char* t)           { this->impl = new ModelElementSTRING;  if(this->impl) this->impl->accept(t); }
ModelElement::ModelElement(const void* t)           { if(t) this->impl = new ModelElementADDRESS(); else this->impl = new ModelElementNULL(); if(this->impl) this->impl->accept(t); }

// void ModelElement::setType(const MODEL_ELEMENT_TYPE& t)
const ModelElement::MODEL_ELEMENT_TYPE ModelElement::setType(const ModelElement::MODEL_ELEMENT_TYPE& t) {
    switch(t) {
        case ModelElement::MET_UNKNOWN:{ if(this->impl) delete this->impl;this->impl = new ModelElementUNKNOWN(); return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_NULL:   { if(this->impl) delete this->impl;this->impl = new ModelElementNULL();    return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_VOID:   { if(this->impl) delete this->impl;this->impl = new ModelElementVOID();    return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_ADDRESS:{ if(this->impl) delete this->impl;this->impl = new ModelElementADDRESS(); return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_BOOL:   { if(this->impl) delete this->impl;this->impl = new ModelElementBOOL();    return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_CHAR:   { if(this->impl) delete this->impl;this->impl = new ModelElementCHAR();    return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_CHAR_U: { if(this->impl) delete this->impl;this->impl = new ModelElementCHAR_U();  return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_SHORT:  { if(this->impl) delete this->impl;this->impl = new ModelElementSHORT();   return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_SHORT_U:{ if(this->impl) delete this->impl;this->impl = new ModelElementSHORT_U(); return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_INT:    { if(this->impl) delete this->impl;this->impl = new ModelElementINT();     return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_INT_U:  { if(this->impl) delete this->impl;this->impl = new ModelElementINT_U();   return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_LONG:   { if(this->impl) delete this->impl;this->impl = new ModelElementLONG();    return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_LONG_U: { if(this->impl) delete this->impl;this->impl = new ModelElementLONG_U();  return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_FLOAT:  { if(this->impl) delete this->impl;this->impl = new ModelElementFLOAT();   return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_DOUBLE: { if(this->impl) delete this->impl;this->impl = new ModelElementDOUBLE();  return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_ARRAY:  { if(this->impl) delete this->impl;this->impl = new ModelElementARRAY();   return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_MAP:    { if(this->impl) delete this->impl;this->impl = new ModelElementMAP();     return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        case ModelElement::MET_STRING: { if(this->impl) delete this->impl;this->impl = new ModelElementSTRING();  return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
        //case ModelElement::MET_MODEL:  { if(this->impl) delete this->impl;this->impl = new ModelElementMODEL();   return this->impl ? this->impl->type : ModelElement::MET_UNKNOWN; }break;
    default:break;
    }
    return ModelElement::MET_UNKNOWN;
}

ModelElement::~ModelElement() {
    if(impl) delete impl;
}

ModelElement::MODEL_ELEMENT_TYPE ModelElement::type() const {
    if(impl) return impl->type;
    return ModelElement::MET_UNKNOWN;
}

const char* ModelElement::typeString() { return this->impl ? MET_STRING_ARRAY[this->impl->type] : MET_STRING_ARRAY[ModelElement::MET_UNKNOWN]; }

bool ModelElement::as(bool& t)           const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(char& t)           const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(unsigned char& t)  const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(short& t)          const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(unsigned short& t) const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(int& t)            const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(unsigned int& t)   const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(long& t)           const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(unsigned long& t)  const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(float& t)          const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(double& t)         const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(char** t)          const { return this->impl ? impl->as(t) : false; }
bool ModelElement::as(void** t)          const { return this->impl ? impl->as(t) : false; }

bool ModelElement::accept(bool& v)             { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(char& v)             { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(unsigned char& v)    { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(short& v)            { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(unsigned short& v)   { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(int& v)              { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(unsigned int& v)     { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(long& v)             { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(unsigned long& v)    { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(float& v)            { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(double& v)           { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(char* v)             { return this->impl ? impl->accept(v) : false; }
bool ModelElement::accept(void* v)             { return this->impl ? impl->accept(v) : false; }

ModelElement::operator bool()                   const { bool           r = false; if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator char()                   const { char           r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator unsigned char()          const { unsigned char  r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator short()                  const { short          r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator unsigned short()         const { unsigned short r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator int()                    const { int            r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator unsigned int()           const { unsigned int   r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator long()                   const { long           r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator unsigned long()          const { unsigned long  r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator float()                  const { float          r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator double()                 const { double         r = 0;     if(this->impl) { this->impl->as(r); } return r;     }
ModelElement::operator char*()                  const { char*          r = 0;     if(this->impl) { this->impl->as(&r);} return r;     }
ModelElement::operator void*()                  const { void*          r = 0;     if(this->impl) { this->impl->as(&r);} return r;     }
ModelElement::operator MODEL_ELEMENT_TYPE()     const { if(this->impl) return this->impl->type; return ModelElement::MET_UNKNOWN;     }

void ModelElement::echo(const unsigned int& offset) { if(this->impl) this->impl->echo(offset);else  {}}
 
unsigned int  ModelElement::appendSubelement(const ModelElement* e)                  { return this->impl ? this->impl->appendSubelement(e)      : 0; }
unsigned int  ModelElement::insertSubelement(const ModelElement* e,const char* name) { return this->impl ? this->impl->insertSubelement(e,name) : 0; }
unsigned int  ModelElement::removeSubelement(const ModelElement* e)                  { return this->impl ? this->impl->removeSubelement(e)      : 0; }
unsigned int  ModelElement::removeSubelement(const char* name)                       { return this->impl ? this->impl->removeSubelement(name)   : 0; }
unsigned int  ModelElement::removeSubelement(const unsigned int& index)              { return this->impl ? this->impl->removeSubelement(index)  : 0; }
unsigned int  ModelElement::subelementCount()                                  const { return this->impl ? this->impl->subelementCount()        : 0; }
const ModelElement* ModelElement::subelementAt(const char* key)                const { return this->impl ? this->impl->subelementAt(key)        : 0; }
const ModelElement* ModelElement::subelementAt(const unsigned int& index)      const { return this->impl ? this->impl->subelementAt(index)      : 0; }

ModelElement& ModelElement::operator = (const bool& v)           { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const char* v)           { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const char& v)           { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const unsigned char& v)  { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const short& v)          { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const unsigned short& v) { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const int& v)            { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const unsigned int& v)   { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const long& v)           { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const unsigned long& v)  { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const float& v)          { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const double& v)         { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const void* v)           { if(impl) impl->accept(v);return *this; }
ModelElement& ModelElement::operator = (const ModelElement& e)   { /*if(impl) impl->accept(v);*/return *this; }

bool ModelElement::operator == (const MODEL_ELEMENT_TYPE& type)   const { return impl && impl->type == type ? true : false; }
bool ModelElement::operator == (const ModelElement* e)            const { return false; }
bool ModelElement::operator == (const ModelElement& e)            const { return false; }

bool ModelElement::operator == (const char& v)            const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const unsigned char& v)   const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const short& v)           const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const unsigned short& v)  const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const int& v)             const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const unsigned int& v)    const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const float& v)           const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const double& v)          const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const char* v)            const { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const void* v)            const { if(impl) return impl->equal(v);return false; }
