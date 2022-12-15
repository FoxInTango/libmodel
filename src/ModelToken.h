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
        ModelTokenXML_t type; /** <top id="something" name="yourname" ><sub id="" name=""/> </top>*/
};
struct ModelTokenJSON {
    char* token;
    ModelTokenJSON_t type; /** {"object":{},"array":[],"string":"something","number":124,"bool":false } */
};

std::vector<ModelTokenJSON*>* loadJSONFile(const char* path);
std::vector<ModelTokenJSON*>* loadJSONString(const char* content,const unsigned int& length);
namespaceEnd
#endif
