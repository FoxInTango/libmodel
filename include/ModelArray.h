#ifndef _MODEL_ARRAY_H_
#define _MODEL_ARRAY_H_

#include "ModelElement.h"
#include "libcpp/libcpp.h"

namespace foxintango {
class foxintangoAPI ModelArray :public ModelElement {
public:
    ModelArray();
    virtual ~ModelArray();
public:
    virtual ModelElement* subelementAt(const unsigned int& index);
};
}
#endif
