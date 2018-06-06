// Copyright (C) 2018, Guy Barrand. All rights reserved.
// See the file gopaw.license for terms.


extern "C" {
  int gopaw_kuip(void*);
}

#include <kuip/ksys.h>
#include <kuip/kfor.h>
#include <kuip/kuser.h>

#include "session"

#ifdef APP_USE_PYTHON
#include <inlib/args>
#endif

int gopaw_kuip(void* a_tag) {

  gopaw::session& _sess = *((gopaw::session*)a_tag);
  std::ostream& out = _sess.out();
  
  std::string cmd_path = ku_path() ? ku_path() : "";
  //std::string cmd_name = ku_name();

  if(_sess.verbose_level()) out << "gopaw_kuip : execute " << inlib::sout(cmd_path) << std::endl;

  ///////////////////////////////////////////////////////
  /// SESSION ///////////////////////////////////////////
  ///////////////////////////////////////////////////////
  if(cmd_path=="/SESSION/NOW") {
    //std::string NAME = ku_gets();
    _sess.set_atime(inlib::atime::now());
    return gopaw::status_success();
  }
  
  if(cmd_path=="/SESSION/ELAPSED") {
    _sess.out() << "elapsed : " << inlib::atime::elapsed(_sess.atime()) << std::endl;
    return gopaw::status_success();
  }
  
  if(cmd_path=="/SESSION/MOVE") {
    std::string FROM = ku_gets();
    std::string TO = ku_gets();

    if(_sess.verbose_level()) {
      out << "gopaw_kuip : " << cmd_path
          << " FROM= " << inlib::sout(FROM) 
          << " TO= " << inlib::sout(TO) 
          << std::endl;
    }
    
    if(!inlib::file_system::mv(FROM,TO)) {
      out << "gopaw_kuip : " << cmd_path << " inlib::file_system::mv() failed." << std::endl;
      return gopaw::status_failure();
    }

    return gopaw::status_success();
  }
  
  if(cmd_path=="/SESSION/PYTHON") {
#ifdef APP_USE_PYTHON
    std::string FILE = ku_gets();

    if(_sess.verbose_level()) {
      out << "gopaw_kuip : " << cmd_path
          << " FILE= " << inlib::sout(FILE) 
          << std::endl;
    }
    
    std::string sfile;
    inlib::file_name(FILE,sfile); //to expand environment variables.

    if(_sess.verbose_level()) {
      out << "gopaw_kuip : file " << inlib::sout(sfile) << ". FILE is " << inlib::sout(FILE) << "." << std::endl;
    }

    gopaw::iwidget* widget = _sess.ui().current_widget();
    if(widget) {
      inlib::args args;bool done;
      _sess.py_opener().open(sfile,widget->viewer(),args,done);
    }
    
    return gopaw::status_success();
#else  
    out << "gopaw_kuip : " << cmd_path << " : gopaw not built with -DAPP_USE_PYTHON." << std::endl;
    return gopaw::status_failure();
#endif
  }
  
  ///////////////////////////////////////////////////////
  /// VIEWER ////////////////////////////////////////////
  ///////////////////////////////////////////////////////
  if(cmd_path=="/VIEWER/RENDER") {
    //std::string NAME = ku_gets();
    _sess.ui().render_it();
    return gopaw::status_success();
  }
  
  if(cmd_path=="/VIEWER/SYNCHRONIZE") {
    _sess.ui().synchronize();
    return gopaw::status_success();
  }
  
  if(cmd_path=="/VIEWER/PAGE/SET_LAYOUT") { //use from ioda (exlib::KUIP::opener).
    //_sess.out() << "gopaw_kuip : " << cmd_path << " : debug." << std::endl;
    inlib::sg::plots* _page = _sess.find_plots(gopaw::s_current());
    if(_page) {
      _sess.set_plots_layout(*_page);
      _sess.set_plots_zone(*_page);
    }
    return gopaw::status_success();
  }
  
  _sess.out() << "gopaw_kuip : " << cmd_path << " : unknow command." << std::endl;

  return gopaw::status_failure();
}
