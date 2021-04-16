#include "StringWrapper.h"

  StringWrapper::StringWrapper(const char * s):Object("String"){

    size = strlen(s);
    str = new char[size + 1];
    strcpy(str,s);

  }
