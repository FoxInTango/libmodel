#include "../include/ModelElement.h"
using namespace foxintango;

#include <string>

namespace {
class ModelElementIMPL {
public:
    ModelElement::MODEL_ELEMENT_TYPE type;
    ModelElement::MODEL_ELEMENT_STATUS status;
public:
    ModelElementIMPL(){

    }
   
   ~ModelElementIMPL(){

   }
public:

};

class ModelElementNULL :public ModelElementIMPL {
public:
    ModelElementNULL() {
       type   = ModelElement::MET_NULL;
       status = ModelElement::MES_OK;
    }
   
   ~ModelElementNULL() {

   }
public:

};

class ModelElementVOID :public ModelElementIMPL {
public:
    ModelElementVOID() {
        type   = ModelElement::MET_VOID;
        status = ModelElement::MES_OK;
    }
   
   ~ModelElementVOID() {

   }
};

class ModelElementADDRESS :public ModelElementIMPL {
public:
    void* value;
public:
    ModelElementADDRESS() {
        type   = ModelElement::MET_ADDRESS;
        status = ModelElement::MES_OK;
    }
   
   ~ModelElementADDRESS() {
   
   }
};

class ModelElementBOOL :public ModelElementIMPL {
public:
    bool value;
public:
    ModelElementBOOL() {
        type   = ModelElement::MET_BOOL;
        status = ModelElement::MES_OK;
    }
   
   ~ModelElementBOOL() { 
   }
};

class ModelElementCHAR :public ModelElementIMPL {
public:
    char value;
public:
    ModelElementCHAR() {
        type   = ModelElement::MET_CHAR;
        status = ModelElement::MES_OK;
    }

   ~ModelElementCHAR() {

   }
};

class ModelElementCHAR_U :public ModelElementIMPL {
public:
    unsigned char value;
public:
    ModelElementCHAR_U() {
        type   = ModelElement::MET_CHAR_U;
        status = ModelElement::MES_OK;
    }

   ~ModelElementCHAR_U() {

   }
};

class ModelElementSHORT :public ModelElementIMPL {
public:
    short value;
public:
    ModelElementSHORT() {
        type   = ModelElement::MET_SHORT;
        status = ModelElement::MES_OK;
    }

   ~ModelElementSHORT() {

   }
};

class ModelElementSHORT_U :public ModelElementIMPL {
public:
    unsigned short value;
public:
    ModelElementSHORT_U() {
        type   = ModelElement::MET_SHORT_U;
        status = ModelElement::MES_OK;
    }

   ~ModelElementSHORT_U() {

   }
};

class ModelElementINT :public ModelElementIMPL {
public:
    int value;
public:
    ModelElementINT() {
        type   = ModelElement::MET_INT;
        status = ModelElement::MES_OK;
    }

   ~ModelElementINT() {

   }
};

class ModelElementINT_U :public ModelElementIMPL {
public:
    unsigned int value;
public:
    ModelElementINT_U() {
        type   = ModelElement::MET_INT_U;
        status = ModelElement::MES_OK;
    }

   ~ModelElementINT_U() {

   }
};

class ModelElementLONG :public ModelElementIMPL {
public:
    long value;
public:
    ModelElementLONG() {
        type   = ModelElement::MET_LONG;
        status = ModelElement::MES_OK;
    }

   ~ModelElementLONG() {

   }
};

class ModelElementDOUBLE :public ModelElementIMPL {
public:
    double value;
public:
    ModelElementDOUBLE() {
        type   = ModelElement::MET_DOUBLE;
        status = ModelElement::MES_OK;
    }

   ~ModelElementDOUBLE() {

   }
};

}
