#include "../include/Model.h"
//#include "json.hpp"
using namespace foxintango;
//using json = nlohmann::json;

//void model_from_json(Model& m,json& j);
//void walk_through_json(ModelElement* e,json& j);

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
            //json j = json::parse(buffer);
            //model_from_json(*this,j);
        }break;
        default:break;
    }

    return MS_NULL;
}

Model::MODEL_STATUS Model::encode(char* buffer,const MODEL_FORMAT& format) {

    return MS_NULL;
}

Model::MODEL_STATUS Model::loadFile(const char* path) {

    return MS_NULL;
}

Model::MODEL_STATUS Model::saveFile(const char* path) {

    return MS_NULL;
}

/**
void model_from_json(Model& m,json& j) {
    switch(j.type()) {
        case json::value_t::null:{
            ModelElement* e = new ModelElement(ModelElement::MET_NULL); 
            m.insertSubelement(e,"root"); 
            }break;
        case json::value_t::boolean:{ 
            bool v = j.get<bool>();
            ModelElement* e = new ModelElement(ModelElement::MET_BOOL);
            *e = v;
            m.insertSubelement(e,"root"); 
            }break;
        case json::value_t::number_integer: { 
            int v = j.get<int>();
            ModelElement* e = new ModelElement(ModelElement::MET_INT);
            *e = v;
            m.insertSubelement(e,"root"); 
            }break;
        case json::value_t::number_unsigned:{ 
            unsigned int v = j.get<unsigned int>();
            ModelElement* e = new ModelElement(ModelElement::MET_INT_U);
            *e = v;
            m.insertSubelement(e,"root"); 
            }break;
        case json::value_t::number_float:{ 
            float v = j.get<float>();
            ModelElement* e = new ModelElement(ModelElement::MET_FLOAT);
            *e = v;
            m.insertSubelement(e,"root"); 
            }break;
        case json::value_t::string:         { 
            std::string v = j.get<std::string>();
            ModelElement* e = new ModelElement(ModelElement::MET_STRING);
            *e = v.c_str();
            m.insertSubelement(e,"root"); 
            }break;
        case json::value_t::array:{
             ModelArray* e = new ModelArray();m.insertSubelement(e,"root");
             for(json::iterator i = j.begin(); i != j.end(); ++i) {
                walk_through_json(e,*i);
             }
        }break;
        case json::value_t::object:{
             for(json::iterator i = j.begin(); i != j.end(); ++i) {
                walk_through_json(&m,*i);
             }
        }break;
        case json::value_t::binary:{}break;
        case json::value_t::discarded:{}break;
        default:break;
    }
}
*/


void model_element_join(ModelElement* p,ModelElement* e,const char* ename) {
    if(p && *p == ModelElement::MET_ARRAY) { p->appendSubelement(e);}
    else if( p && *p == ModelElement::MET_MAP) {p->insertSubelement(e,ename);}
}
/**
 * root:
 *     object ->this
 *     meta   ->this->
 *     array  ->this->

void walk_through_json(ModelElement* e,json& j) {
    for(json::iterator iter = j.begin(); iter != j.end(); ++iter) {
    //std::cout << it.key() << " : " << it.value() << "\n";
        switch(iter->type()) {
            case json::value_t::null:{
                
            }break;
            case json::value_t::boolean:        { ModelElement* v = new ModelElement(j.get<bool>());               model_element_join(e,v,iter.key().c_str());}break;//判断e类型
            case json::value_t::number_integer: { ModelElement* v = new ModelElement(j.get<int>());                model_element_join(e,v,iter.key().c_str());}break;
            case json::value_t::number_unsigned:{ ModelElement* v = new ModelElement(j.get<unsigned int>());       model_element_join(e,v,iter.key().c_str());}break;
            case json::value_t::number_float:   { ModelElement* v = new ModelElement(j.get<float>());              model_element_join(e,v,iter.key().c_str());}break;
            case json::value_t::string:         { ModelElement* v = new ModelElement(j.get<std::string>().c_str());model_element_join(e,v,iter.key().c_str());}break;
            case json::value_t::array:{
                 ModelArray* array = new ModelArray();
                 model_element_join(e,array,iter.key().c_str());
                 for(json::iterator i = j.begin(); i != iter->end(); ++i) {
                     walk_through_json(array,*i);
                 }
            }break;
            case json::value_t::object:{
                 ModelMap* map = new ModelMap();
                 model_element_join(e,map,iter.key().c_str());
                 for(json::iterator i = iter->begin(); i != iter->end(); ++i) {
                     walk_through_json(map,*i);
                 }
            }break;
            case json::value_t::binary:{
            }break;
            case json::value_t::discarded:{}break;
            default:break;
        }
    }
}*/
