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
        MS_BAD_PATH,
        MS_BAD_BUF,
        MS_BAD_FORMAT,
        MS_NULL,
        MS_OK
    }MODEL_STATUS;
    typedef enum _MODEL_FORMAT {
        MF_XML,
        MF_YML,
        MF_JSON
    }MODEL_FORMAT;
public:
    Model();
    Model(const char* path);
   ~Model();
public:
   MODEL_STATUS decode(char* buffer,const MODEL_FORMAT& format);
   MODEL_STATUS encode(char* buffer,const MODEL_FORMAT& format);
   MODEL_STATUS loadFile(const char* path);
   MODEL_STATUS saveFile(const char* path);
public:

};
}
#endif
