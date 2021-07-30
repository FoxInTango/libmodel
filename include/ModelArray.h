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
    int appendSubelement(const ModelElement* e);
    int insertSubelement(const ModelElement* e,const int& index);
    int removeSubelement(const ModelElement* e);
    int removeSubelement(const int& index);
public:
    virtual ModelElement* subelementAt(const unsigned int& index);
};
}
#endif
