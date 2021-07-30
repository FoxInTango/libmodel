#include "../include/Model.h"
#include "json.hpp"
using namespace foxintango;
using json = nlohmann::json;

Model::Model() {
    setType(ModelElement::MET_MODEL);
}

Model::Model(const char* path) {
    setType(ModelElement::MET_MODEL);

    loadFile(path);
}

Model::~Model() {

}

Model::MODEL_STATUS Model::decode(char* buffer,const MODEL_FORMAT& format) {
    if(!buffer) return MS_BAD_BUF; 
    switch(format) {
        case MF_XML:{}break;
        case MF_YML:{}break;
        case MF_JSON:{
            json j = json::parse(buffer);

        }break;
        default:break;
    }

    return MS_NULL;
}

Model::MODEL_STATUS Model::encode(char* buffer,const MODEL_FORMAT& format) {

}

Model::MODEL_STATUS Model::loadFile(const char* path) {

}

Model::MODEL_STATUS Model::saveFile(const char* path) {

}
