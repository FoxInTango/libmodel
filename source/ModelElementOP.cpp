#include "../include/ModelElement.h"
using namespace foxintango;

/**
 * int operator = (int& v,float& e) {
 *
 * }
 * */
bool operator << (bool& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,bool& v) { return e.as(v); }

bool operator << (char& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,char& v) { return e.as(v); }

bool operator << (unsigned char& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,unsigned char& v) { return e.as(v); }

bool operator << (short& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,short& v) { return e.as(v); }

bool operator << (unsigned short& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,unsigned short& v) { return e.as(v); }

bool operator << (int& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,int& v) { return e.as(v); }

bool operator << (unsigned int& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,unsigned int& v) { return e.as(v); }

bool operator << (long& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,long& v) { return e.as(v); }

bool operator << (unsigned long& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,unsigned long& v) { return e.as(v); }

bool operator << (float& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,float& v) { return e.as(v); }

bool operator << (double& v,ModelElement& e) { return e.as(v); }

bool operator >> (ModelElement& e,double& v) { return e.as(v); }
