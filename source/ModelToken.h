#ifndef _MODEL_TOKEN_H_
#define _MODEL_TOKEN_H_

#include <libcpp/libcpp.h>
#include <vector>
namespaceBegin(foxintango)
enum   ModelFormat      { MF_XML,MF_YML,MF_JSON }; 
enum   ModelTokenXML_t  { MTX_QUOT,MTX_EQUAL,MTX_ANGULAR_L,MTX_ANGULAR_R };
enum   ModelTokenJSON_t { MTJ_QUOT,MTJ_COMMA,MTJ_ARRAY_L,MTJ_ARRAY_R,MTJ_OBJECT_L,MTJ_OBJECT_R };

struct ModelTokenXML {
        char* token;
        ModelTokenXML_t type;
};
struct ModelTokenJSON {
    char* token;
    ModelTokenJSON_t type;
};

std::vector<ModelTokenJSON*>* loadJSONFile(const char* path);
std::vector<ModelTokenJSON*>* loadJSONString(const char* content,const unsigned int& length);
namespaceEnd
#endif
