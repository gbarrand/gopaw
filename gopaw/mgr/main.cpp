// Copyright (C) 2010, Guy Barrand. All rights reserved.
// See the file gopaw.license for terms.

#include "../gopaw/main"

#include <exlib/app/WebGL/main_cpp>

int main(int argc,char** argv) {return exlib_main<gopaw::context,gopaw::main>("gopaw",argc,argv);}

//exlib_build_use inlib expat
//exlib_build_use exlib png jpeg zlib inlib_glutess freetype kernel
