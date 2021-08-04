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
