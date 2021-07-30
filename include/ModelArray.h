#ifndef _MODEL_ARRAY_H_
#define _MODEL_ARRAY_H_

#include "ModelElement.h"
#include <libcpp/libcpp.h>

namespace foxintango {
class ModelArrayIMPL;
class foxintangoAPI ModelArray :public ModelElement {
protected:
    ModelArrayIMPL* array;
public:
    ModelArray();
    virtual ~ModelArray();
public:
    unsigned int appendSubelement(const ModelElement* e);
    unsigned int insertSubelement(const ModelElement* e,const int& index);
    unsigned int removeSubelement(const ModelElement* e);
    unsigned int removeSubelement(const int& index);
    unsigned int subelementCount();
public:
    virtual ModelElement* subelementAt(const unsigned int& index);
};
}
#endif
