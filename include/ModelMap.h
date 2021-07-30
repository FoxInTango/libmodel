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
    unsigned int insertSubelement(const ModelElement* e,const char* name);
    unsigned int removeSubelement(const char* name);
    unsigned int subelementCount();
public:
    virtual ModelElement* subelementAt(const char* name);
};
}
#endif
