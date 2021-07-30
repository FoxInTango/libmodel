#include "../include/ModelElement.h"
using namespace foxintango;

#include <string>
#include <cstring>

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
/** 数值型判断 需要进一步细化 
 * Ox000002
 * 0.1f
 *
 * */
inline bool is_number_string (const char* v) {
    size_t l = strlen(v);

    for(size_t i = 0;i < l;i ++) {
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

namespace foxintango {
/**
 * NOTE:
 * element TO char* 
 * char*   TO element
 * */
class ModelElementIMPL {
public:
    ModelElement::MODEL_ELEMENT_TYPE   type;
    ModelElement::MODEL_ELEMENT_STATUS status;
public:
    ModelElementIMPL(){
    }
   
   virtual ~ModelElementIMPL(){
   }
public:
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {t = value;return true;}
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
    virtual bool accept(const void* t)          {value = const_cast<void*>(t);return false;}
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
    virtual bool equal(const void* t)          {return value == t ? true : false;}
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
    virtual bool as(bool& t)          {t = value;return true;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {t = value;return true;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {t = value;return true;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {t = value;return true;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){t = value;return true;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool equal(const bool& t)          {return false;}
    virtual bool equal(const char& t)          {return false;}
    virtual bool equal(const unsigned char& t) {return false;}
    virtual bool equal(const short& t)         {return false;}
    virtual bool equal(const unsigned short& t){return value == t ? true : false;}
    virtual bool equal(const int& t)           {return false;}
    virtual bool equal(const unsigned int& t)  {return false;}
    virtual bool equal(const long& t)          {return false;}
    virtual bool equal(const unsigned long& t) {return false;}
    virtual bool equal(const float& t)         {return false;}
    virtual bool equal(const double& t)        {return false;}
    virtual bool equal(const char* t)          {return false;}
    virtual bool equal(const void* t)          {return false;}
};

class ModelElementINT :public ModelElementIMPL {
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {t = value;return true;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {t = value;return true;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {t = value;return true; }
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {t = value;return true;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {t = value;return true;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {t = value;return true;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
};

class ModelElementSTRING :public ModelElementIMPL {
public:
    std::string value;
public:
    ModelElementSTRING() {
        type   = ModelElement::MET_STRING;
        status = ModelElement::MES_OK;
    }

    ~ModelElementSTRING() {
    }
public:
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    virtual bool equal(const char* t)          {return value == t ? true : false;}
    virtual bool equal(const void* t)          {return false;}
};

class ModelElementARRAY :public ModelElementIMPL {
public:
    ModelElementARRAY() {
        type   = ModelElement::MET_ARRAY;
        status = ModelElement::MES_OK;
    }

    ~ModelElementARRAY() {
    }
public:
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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

class ModelElementMAP :public ModelElementIMPL {
public:
    ModelElementMAP() {
        type   = ModelElement::MET_MAP;
        status = ModelElement::MES_OK;
    }

    ~ModelElementMAP() {
    }
public:
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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

class ModelElementMODEL :public ModelElementIMPL {
public:
    ModelElementMODEL() {
        type   = ModelElement::MET_MAP;
        status = ModelElement::MES_OK;
    }

    ~ModelElementMODEL() {
    }
public:
    virtual bool as(bool& t)          {return false;}
    virtual bool as(char& t)          {return false;}
    virtual bool as(unsigned char& t) {return false;}
    virtual bool as(short& t)         {return false;}
    virtual bool as(unsigned short& t){return false;}
    virtual bool as(int& t)           {return false;}
    virtual bool as(unsigned int& t)  {return false;}
    virtual bool as(long& t)          {return false;}
    virtual bool as(unsigned long& t) {return false;}
    virtual bool as(float& t)         {return false;}
    virtual bool as(double& t)        {return false;}
    virtual bool as(char* t)          {return false;}
    virtual bool as(void* t)          {return false;}
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
    case ModelElement::MET_MODEL:  { this->impl = new ModelElementMODEL();   }break;
    default:break;
    }
}

void ModelElement::setType(const MODEL_ELEMENT_TYPE& t){
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
    case ModelElement::MET_MODEL:  { this->impl = new ModelElementMODEL();   }break;
    default:break;
    }
}

ModelElement::~ModelElement() {
    if(impl) delete impl;
}

bool ModelElement::as(bool& t) {
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(char& t) {
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(unsigned char& t){ 
    if(impl){
        return impl->as(t);
    }
    return false; 
}

bool ModelElement::as(short& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(unsigned short& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(int& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(unsigned int& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(long& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(unsigned long& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(float& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(double& t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(char* t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

bool ModelElement::as(void* t){ 
    if(impl){
        return impl->as(t);
    }
    return false;
}

ModelElement* ModelElement::subelementAt(const char* key){
    return 0;
}

ModelElement* ModelElement::subelementAt(const unsigned int& index){
    return 0;
}

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
ModelElement& ModelElement::operator = (const ModelElement& e)   { /*if(impl) impl->accept(v);*/return *this; }

bool ModelElement::operator == (const MODEL_ELEMENT_TYPE& type)  { return impl && impl->type == type ? true : false;}
bool ModelElement::operator == (const ModelElement* e) {return false;}
bool ModelElement::operator == (const ModelElement& e) {return false;}

bool ModelElement::operator == (const char& v)           { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const unsigned char& v)  { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const short& v)          { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const unsigned short& v) { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const int& v)            { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const unsigned int& v)   { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const float& v)          { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const double& v)         { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const char* v)           { if(impl) return impl->equal(v);return false; }
bool ModelElement::operator == (const void* v)           { if(impl) return impl->equal(v);return false; }

ModelElement* ModelElement::operator [](const int&  index) { return subelementAt(index); }
ModelElement* ModelElement::operator [](const char* name)  { return subelementAt(name);  }
