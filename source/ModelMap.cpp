#include "../include/ModelMap.h"
#include <libcpp/libcpp.h>
using namespace foxintango;

#include <string>
#include <map>

namespaceBegin(foxintango)
class ModelMapIMPL {
public:
    std::map<std::string,ModelElement*> subelements;
public:
    ModelMapIMPL () {
    
    }
    ~ModelMapIMPL () {

    }
};

namespaceEnd

ModelMap::ModelMap() {
    setType(ModelElement::MET_MAP);
    map = new ModelMapIMPL();
}

ModelMap::~ModelMap() {
    if(map) delete map;
}

unsigned int ModelMap::insertSubelement(const ModelElement* e,const char* name) {
    if(map) {
        map->subelements.insert(std::pair<std::string,ModelElement*>(name,const_cast<ModelElement*>(e)));
        return map->subelements.size();
    }
    return 0;
}
unsigned int ModelMap::removeSubelement(const char* name) {
    if(map) {
        map->subelements.erase(name);
    }
    return 0;
}
unsigned int ModelMap::subelementCount() {
    if(map) {
        return map->subelements.size();
    }
    return 0;
}

ModelElement* ModelMap::subelementAt(const char* name) {
    if(map) {
        return  map->subelements.find(name)->second;
    }

    return 0;
}

