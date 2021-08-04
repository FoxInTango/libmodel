#include "../include/ModelElement.h"
using namespace foxintango;

bool operator << (ModelElement& e,bool& v)          { return e.accept(v); }
bool operator << (ModelElement& e,char& v)          { return e.accept(v); }
bool operator << (ModelElement& e,unsigned char& v) { return e.accept(v); }
bool operator << (ModelElement& e,short& v)         { return e.accept(v); }
bool operator << (ModelElement& e,unsigned short& v){ return e.accept(v); }
bool operator << (ModelElement& e,int& v)           { return e.accept(v); }
bool operator << (ModelElement& e,unsigned int& v)  { return e.accept(v); }
bool operator << (ModelElement& e,long& v)          { return e.accept(v); }
bool operator << (ModelElement& e,unsigned long& v) { return e.accept(v); }
bool operator << (ModelElement& e,float& v)         { return e.accept(v); }
bool operator << (ModelElement& e,double& v)        { return e.accept(v); }
bool operator << (ModelElement& e,char* v)          { return e.accept(v); }
bool operator << (ModelElement& e,void* v)          { return e.accept(v); }

bool operator >> (ModelElement& e,bool& v)          { return e.as(v); }
bool operator >> (ModelElement& e,char& v)          { return e.as(v); }
bool operator >> (ModelElement& e,unsigned char& v) { return e.as(v); }
bool operator >> (ModelElement& e,short& v)         { return e.as(v); }
bool operator >> (ModelElement& e,unsigned short& v){ return e.as(v); }
bool operator >> (ModelElement& e,int& v)           { return e.as(v); }
bool operator >> (ModelElement& e,unsigned int& v)  { return e.as(v); }
bool operator >> (ModelElement& e,long& v)          { return e.as(v); }
bool operator >> (ModelElement& e,unsigned long& v) { return e.as(v); }
bool operator >> (ModelElement& e,float& v)         { return e.as(v); }
bool operator >> (ModelElement& e,double& v)        { return e.as(v); }
bool operator >> (ModelElement& e,char* v)          { return e.as(v); }
bool operator >> (ModelElement& e,void* v)          { return e.as(v); }

bool operator >> (bool& v,          ModelElement& e){ return e.accept(v); }
bool operator >> (char& v,          ModelElement& e){ return e.accept(v); }
bool operator >> (unsigned char& v, ModelElement& e){ return e.accept(v); }
bool operator >> (short& v,         ModelElement& e){ return e.accept(v); }
bool operator >> (unsigned short& v,ModelElement& e){ return e.accept(v); }
bool operator >> (int& v,           ModelElement& e){ return e.accept(v); }
bool operator >> (unsigned int& v,  ModelElement& e){ return e.accept(v); }
bool operator >> (long& v,          ModelElement& e){ return e.accept(v); }
bool operator >> (unsigned long& v, ModelElement& e){ return e.accept(v); }
bool operator >> (float& v,         ModelElement& e){ return e.accept(v); }
bool operator >> (double& v,        ModelElement& e){ return e.accept(v); }
bool operator >> (char* v,          ModelElement& e){ return e.accept(v); }
bool operator >> (void* v,          ModelElement& e){ return e.accept(v); }

bool operator << (bool& v,          ModelElement& e){ return e.as(v); }
bool operator << (char& v,          ModelElement& e){ return e.as(v); }
bool operator << (unsigned char& v, ModelElement& e){ return e.as(v); }
bool operator << (short& v,         ModelElement& e){ return e.as(v); }
bool operator << (unsigned short& v,ModelElement& e){ return e.as(v); }
bool operator << (int& v,           ModelElement& e){ return e.as(v); }
bool operator << (unsigned int& v,  ModelElement& e){ return e.as(v); }
bool operator << (long& v,          ModelElement& e){ return e.as(v); }
bool operator << (unsigned long& v, ModelElement& e){ return e.as(v); }
bool operator << (float& v,         ModelElement& e){ return e.as(v); }
bool operator << (double& v,        ModelElement& e){ return e.as(v); }
bool operator << (char* v,          ModelElement& e){ return e.as(v); }
bool operator << (void* v,          ModelElement& e){ return e.as(v); }

/**
bool operator << (ModelElement& e,bool& v)          { return e.accept(v); }
bool operator >> (bool& v,ModelElement& e)          { return e.accept(v); }
bool operator >> (char& v,ModelElement& e)          { return e.accept(v); }
bool operator << (ModelElement& e,char& v)          { return e.accept(v); }
bool operator >> (unsigned char& v,ModelElement& e) { return e.accept(v); }
bool operator << (ModelElement& e,unsigned char& v) { return e.accept(v); }
bool operator >> (short& v,ModelElement& e)         { return e.accept(v); }
bool operator << (ModelElement& e,short& v)         { return e.accept(v); }
bool operator >> (unsigned short& v,ModelElement& e){ return e.accept(v); }
bool operator << (ModelElement& e,unsigned short& v){ return e.accept(v); }
bool operator >> (int& v,ModelElement& e)           { return e.accept(v); }
bool operator << (ModelElement& e,int& v)           { return e.accept(v); }
bool operator >> (unsigned int& v,ModelElement& e)  { return e.accept(v); }
bool operator << (ModelElement& e,unsigned int& v)  { return e.accept(v); }
bool operator >> (long& v,ModelElement& e)          { return e.accept(v); }
bool operator << (ModelElement& e,long& v)          { return e.accept(v); }
bool operator >> (unsigned long& v,ModelElement& e) { return e.accept(v); }
bool operator << (ModelElement& e,unsigned long& v) { return e.accept(v); }
bool operator >> (float& v,ModelElement& e)         { return e.accept(v); }
bool operator << (ModelElement& e,float& v)         { return e.accept(v); }
bool operator >> (double& v,ModelElement& e)        { return e.accept(v); }
bool operator << (ModelElement& e,double& v)        { return e.accept(v); }
bool operator >> (char* v,ModelElement& e)          { return e.accept(v); }
bool operator << (ModelElement& e,char* v)          { return e.accept(v); }
bool operator >> (void* v,ModelElement& e)          { return e.accept(v); }
bool operator << (ModelElement& e,void* v)          { return e.accept(v); }

EXTERN_C bool operator << (bool& v,ModelElement& e)          { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,bool& v)          { return e.as(v); }
EXTERN_C bool operator << (char& v,ModelElement& e)          { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,char& v)          { return e.as(v); }
EXTERN_C bool operator << (unsigned char& v,ModelElement& e) { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,unsigned char& v) { return e.as(v); }
EXTERN_C bool operator << (short& v,ModelElement& e)         { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,short& v)         { return e.as(v); }
EXTERN_C bool operator << (unsigned short& v,ModelElement& e){ return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,unsigned short& v){ return e.as(v); }
EXTERN_C bool operator << (int& v,ModelElement& e)           { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,int& v)           { return e.as(v); }
EXTERN_C bool operator << (unsigned int& v,ModelElement& e)  { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,unsigned int& v)  { return e.as(v); }
EXTERN_C bool operator << (long& v,ModelElement& e)          { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,long& v)          { return e.as(v); }
EXTERN_C bool operator << (unsigned long& v,ModelElement& e) { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,unsigned long& v) { return e.as(v); }
EXTERN_C bool operator << (float& v,ModelElement& e)         { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,float& v)         { return e.as(v); }
EXTERN_C bool foxintangoAPI operator << (double& v,ModelElement& e)        { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,double& v)        { return e.as(v); }
EXTERN_C bool operator << (char* v,ModelElement& e)          { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,char* v)          { return e.as(v); }
EXTERN_C bool operator << (void* v,ModelElement& e)          { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,void* v)          { return e.as(v); }
*/