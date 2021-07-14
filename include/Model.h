#ifndef _MODEL_H_
#define _MODEL_H_

#include <libcpp/libcpp.h>

namespace foxintango {
class foxintangoAPI Model {
public:
    Model();
    Model(const char* path);
   ~Model();
};
}
#endif
