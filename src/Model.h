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
#ifndef _MODEL_H_
#define _MODEL_H_

#include "ModelElement.h"
#include <libcpp/libcpp.h>

namespace foxintango {
class foxintangoAPI Model :public ModelElement {
public:
    typedef enum _MODEL_STATUS {
        MS_DECODE_BAD_PATH,
        MS_DECODE_BAD_BUF,
        MS_DECODE_BAD_FORMAT,
        MS_ENCODE_BAD_PATH,
        MS_ENCODE_BAD_BUF,
        MS_ENCODE_BAD_FORMAT,
        MS_TYPE_SET_OK,
        MS_TYPE_SET_FIXED,
        MS_NULL,
        MS_OK
    }MODEL_STATUS;
    typedef enum _MODEL_FORMAT {
        MF_XML,
        MF_YML,
        MF_JSON
    }MODEL_FORMAT;
public:
    Model(const MODEL_ELEMENT_TYPE& t = MET_MAP);
    /**
     * option: model file path or model content text. 
     */
    Model(const char* option);
    Model(const ModelElement& e);
   ~Model();
public:
   MODEL_STATUS setType(const MODEL_ELEMENT_TYPE& t);
public:
   MODEL_STATUS decode(char* buffer,const MODEL_FORMAT& format);
   MODEL_STATUS encode(char* buffer,const MODEL_FORMAT& format);
   MODEL_STATUS loadFile(const char* path);
   MODEL_STATUS saveFile(const char* path);
public:
virtual unsigned int appendSubelement(const ModelElement* e);
virtual unsigned int insertSubelement(const ModelElement* e,const char* name);
virtual unsigned int removeSubelement(const ModelElement* e);
virtual unsigned int removeSubelement(const char* name);
virtual unsigned int removeSubelement(const unsigned int& index);
virtual unsigned int subelementCount();
virtual ModelElement* subelementAt(const char* key) const ;
virtual ModelElement* subelementAt(const unsigned int& index) const ;
};

}
#endif
