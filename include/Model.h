#ifndef _MODEL_H_
#define _MODEL_H_

#include "ModelMap.h"
#include "ModelArray.h"
#include "ModelElement.h"
#include <libcpp/libcpp.h>

namespace foxintango {
class foxintangoAPI Model :public ModelMap {
public:
    typedef enum _MODEL_STATUS {
        MS_BAD_PATH,
        MS_BAD_BUF,
        MS_BAD_FORMAT,
        MS_NULL,
        MS_OK
    }MODEL_STATUS;
    typedef enum _MODEL_FORMAT {
        MF_XML,
        MF_YML,
        MF_JSON
    }MODEL_FORMAT;
public:
    Model();
    Model(const char* path);
   ~Model();
public:
   MODEL_STATUS decode(char* buffer,const MODEL_FORMAT& format);
   MODEL_STATUS encode(char* buffer,const MODEL_FORMAT& format);
   MODEL_STATUS loadFile(const char* path);
   MODEL_STATUS saveFile(const char* path);
public:

};
}
#endif
