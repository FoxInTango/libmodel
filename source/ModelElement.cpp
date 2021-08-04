#include "../include/ModelElement.h"
using namespace foxintango;

ModelElement::ModelElement()                               { this->impl = 0;             }
ModelElement* ModelElement::operator [](const int&  index) { return subelementAt(index); }
ModelElement* ModelElement::operator [](const char* name)  { return subelementAt(name);  }
