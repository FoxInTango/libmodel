/*
 * libmodel
 *
 * Copyright (C) 2021 FoxInTango <foxintango@yeah.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#include "Model.h"
using namespace foxintango;
#include "ModelToken.h"
#include <libast/libast.h>

/**
Model::Model() {
    ME::setType(ModelElement::MET_UNKNOWN);
}
*/

Model::Model(const MODEL_ELEMENT_TYPE& t) {
    //if( t == ME::setType(t) ) std::cout << "Model set type OK." << std::endl;
    ME::setType(t);
}

Model::Model(const char* path) {
    ME::setType(ModelElement::MET_UNKNOWN);
    /**
     * ASTMatch
     */
    loadFile(path);
}

Model::Model(const ModelElement& e) {
    switch(e.type()) {
    default:break;
    }
}

Model::Model(const ModelElement* e) {
    switch (e->type()) {
    default:break;
    }
}

Model::~Model() {

}

Model::MODEL_STATUS Model::setType(const ME::MODEL_ELEMENT_TYPE& t) {
    return ME::MET_UNKNOWN == ME::type() && t == ME::setType(t) ? Model::MS_TYPE_SET_OK : Model::MS_TYPE_SET_FIXED;
}

Model::MODEL_STATUS Model::decode(char* buffer,const MODEL_FORMAT& format) {
    if(!buffer) return Model::MS_DECODE_BAD_BUF; 
    switch(format) {
        case MF_XML:{}break;
        case MF_YML:{}break;
        case MF_JSON:{
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

unsigned int Model::appendSubelement(const ModelElement* e)                  { return ME::MET_ARRAY == ME::type()                              ? ME::appendSubelement(e)      : 0; }
unsigned int Model::insertSubelement(const ModelElement* e,const char* name) { return ME::MET_MAP   == ME::type()                              ? ME::insertSubelement(e,name) : 0; }
unsigned int Model::removeSubelement(const ModelElement* e)                  { return ME::MET_ARRAY == ME::type() || ME::MET_MAP == ME::type() ? ME::removeSubelement(e)      : 0; }
unsigned int Model::removeSubelement(const char* name)                       { return ME::MET_MAP   == ME::type()                              ? ME::removeSubelement(name)   : 0; }
unsigned int Model::removeSubelement(const unsigned int& index)              { return ME::MET_ARRAY == ME::type()                              ? ME::removeSubelement(index)  : 0; }
unsigned int Model::subelementCount()                                        { return ME::MET_ARRAY == ME::type() || ME::MET_MAP == ME::type() ? ME::subelementCount()        : 0; }
ModelElement* Model::subelementAt(const char* key) const                     { return ME::MET_MAP   == ME::type() || ME::MET_MAP == ME::type() ? ME::subelementAt(key)        : 0; }
ModelElement* Model::subelementAt(const unsigned int& index) const           { return ME::MET_ARRAY == ME::type()                              ? ME::subelementAt(index)      : 0; }
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
