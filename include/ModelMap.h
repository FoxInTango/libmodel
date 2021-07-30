#ifndef _MODEL_MAP_H_
#define _MODEL_MAP_H_

#include "ModelElement.h"
#include "libcpp/libcpp.h"

namespace foxintango {
class ModelMapIMPL;
class foxintangoAPI ModelMap :public ModelElement {
protected:
    ModelMapIMPL* map;
public:
    ModelMap();
    virtual ~ModelMap();
public:
    virtual ModelElement* subelementAt(const char* key);
};
}
#endif
