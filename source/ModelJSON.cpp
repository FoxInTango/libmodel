#include "ModelToken.h"
using namespace foxintango;

namespaceBegin(foxintango)

#define JSON_TOKEN_STRING_QUOT   '"'
#define JSON_TOKEN_COMMA         ','
#define JSON_TOKEN_ARRAY_PREFIX  '['
#define JSON_TOKEN_ARRAY_SUFFIX  ']'
#define JSON_TOKEN_OBJECT_PREFIX '{'
#define JSON_TOKEN_OBJECT_SUFFIX '}'

std::vector<ModelTokenJSON*>* loadTokenFile(const char* path) {
    return 0;
}
std::vector<ModelTokenJSON*>* loadTokenString(const char* content,const unsigned int& length) {
    std::vector<ModelTokenJSON*>* v = new std::vector<ModelTokenJSON*>();
    if(content && v) {
        unsigned int i = 0;
        while(i < length ) {
            switch (content[i]){
                case JSON_TOKEN_STRING_QUOT:{
                    ModelTokenJSON* token = new ModelTokenJSON();
                    if(token) { token->type = MTJ_QUOT; token->token = 0; v->push_back(token); }}break;
                case JSON_TOKEN_COMMA:{
                    ModelTokenJSON* token = new ModelTokenJSON();
                    if(token) { token->type = MTJ_QUOT; token->token = 0; v->push_back(token); }}break;
                case JSON_TOKEN_ARRAY_PREFIX:{
                    ModelTokenJSON* token = new ModelTokenJSON();
                    if(token) { token->type = MTJ_QUOT; token->token = 0; v->push_back(token); }}break;
                case JSON_TOKEN_ARRAY_SUFFIX:{
                    ModelTokenJSON* token = new ModelTokenJSON();
                    if(token) { token->type = MTJ_QUOT; token->token = 0; v->push_back(token); }}break;
                case JSON_TOKEN_OBJECT_PREFIX:{
                    ModelTokenJSON* token = new ModelTokenJSON();
                    if(token) { token->type = MTJ_QUOT; token->token = 0; v->push_back(token); }}break;
                case JSON_TOKEN_OBJECT_SUFFIX:{
                    ModelTokenJSON* token = new ModelTokenJSON();
                    if(token) { token->type = MTJ_QUOT; token->token = 0; v->push_back(token); }}break;
                default:{i++;}break;
            }
        }
    }
    return 0;
}
namespaceEnd
