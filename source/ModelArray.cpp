#include "../include/ModelArray.h"
using namespace foxintango;
#include <vector>
namespaceBegin(foxintango)
class ModelArrayIMPL {
public:
    std::vector<ModelElement*> subelements;
public:
    ModelArrayIMPL() {
    
    }
    ~ModelArrayIMPL() {

    }
};

namespaceEnd

ModelArray::ModelArray() {
    setType(ModelElement::MET_ARRAY);
    this->array = new ModelArrayIMPL();
}

ModelArray::~ModelArray() {
    if(array) delete array;

}


unsigned int ModelArray::appendSubelement(const ModelElement* e) {
    if(array) {
        array->subelements.push_back(const_cast<ModelElement*>(e));
        return array->subelements.size();
    }
    return 0;
}
unsigned int ModelArray::insertSubelement(const ModelElement* e,const int& index){
    if(array) {
        array->subelements.insert(array->subelements.begin() + index,const_cast<ModelElement*>(e));
        return array->subelements.size();
    }
    return 0;
}
unsigned int ModelArray::removeSubelement(const ModelElement* e) {
    if(array) {
        std::vector<ModelElement*>::iterator iter = array->subelements.begin();
        while(iter !=  array->subelements.end()) {
            if(*iter == e) { array->subelements.erase(iter); break; }
            iter ++;
        }
        return array->subelements.size();
    }
    return 0;
}
unsigned int ModelArray::removeSubelement(const int& index) {
    if(array) {
        array->subelements.erase(array->subelements.begin() + index);
        return array->subelements.size();
    }
    return 0;
}
unsigned int ModelArray::subelementCount() {
    if(array) {
        return array->subelements.size();
    }
    return 0;
}
ModelElement* ModelArray::subelementAt(const unsigned int& index) {
    if(array) {
        return array->subelements.at(index);
    }
    return 0;
}