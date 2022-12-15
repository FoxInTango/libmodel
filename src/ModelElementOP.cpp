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
bool operator >> (ModelElement& e,char** v)         { return e.as(v); }
bool operator >> (ModelElement& e,void** v)         { return e.as(v); }

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
bool operator << (char** v,         ModelElement& e){ return e.as(v); }
bool operator << (void** v,         ModelElement& e){ return e.as(v); }

bool operator == (const foxintango::ModelElement::MODEL_ELEMENT_TYPE& type,const foxintango::ModelElement& e) { return e == type; }

bool operator == (const char& v,const foxintango::ModelElement& e)                  { return e == v;    }
bool operator == (const unsigned char& v,const foxintango::ModelElement& e)         { return e == v;    }
bool operator == (const short& v,const foxintango::ModelElement& e)                 { return e == v;    }
bool operator == (const unsigned short& v,const foxintango::ModelElement& e)        { return e == v;    }
bool operator == (const int& v,const foxintango::ModelElement& e)                   { return e == v;    }
bool operator == (const unsigned int& v,const foxintango::ModelElement& e)          { return e == v;    }
bool operator == (const float& v,const foxintango::ModelElement& e)                 { return e == v;    }
bool operator == (const double& v,const foxintango::ModelElement& e)                { return e == v;    }
bool operator == (const char* v,const foxintango::ModelElement& e)                  { return e == v;    }
bool operator == (const void* v,const foxintango::ModelElement& e)                  { return e == v;    }

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
EXTERN_C bool operator << (double& v,ModelElement& e)        { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,double& v)        { return e.as(v); }
EXTERN_C bool operator << (char* v,ModelElement& e)          { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,char* v)          { return e.as(v); }
EXTERN_C bool operator << (void* v,ModelElement& e)          { return e.as(v); }
EXTERN_C bool operator >> (ModelElement& e,void* v)          { return e.as(v); }
*/
