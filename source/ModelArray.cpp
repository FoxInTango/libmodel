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


