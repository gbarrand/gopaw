/* G.Barrand */

#if defined(_MSC_VER)

  #include "H5Tinit_visual.ic"

#elif defined(__APPLE__)

  #include <TargetConditionals.h>

  #if TARGET_OS_IPHONE

  #if defined(TARGET_RT_64_BIT) && (TARGET_RT_64_BIT == 1) 
  #include "H5Tinit_Linux_x86_64.ic"
  #else
  #include "H5Tinit_Linux.ic"
  #endif

  #else /*macOS*/

  #if defined(TARGET_RT_64_BIT) && (TARGET_RT_64_BIT == 1)

  #if defined(TARGET_RT_BIG_ENDIAN)  && (TARGET_RT_BIG_ENDIAN == 1) 
  #error "ourex/hdf5/src/H5Tinit.c : __APPLE__ platform not handled."
  #else
  #include "H5Tinit_macosx_x86_64.ic"
  #endif

  #else

  #if defined(TARGET_RT_BIG_ENDIAN)  && (TARGET_RT_BIG_ENDIAN == 1) 
  #include "H5Tinit_macosx.ic"
  #else
  #include "H5Tinit_macosx_intel.ic"
  #endif

  #endif

  #endif /*TARGET_OS_IPHONE*/

/*
#elif defined(__CYGWIN__)

  #if defined(__GNUC__)
  #include "H5Tinit_CYGWIN.ic"
  #else
  #error "CYGWIN with another compiler than gcc is not yet supported."
  #endif
*/

#elif defined(ANDROID) /*G.Barrand*/

  #if defined(__aarch64__)
  #include "H5Tinit_Linux_x86_64.ic"
  #else
  #include "H5Tinit_Linux.ic"
  #endif

#elif defined(__linux__)

  #if defined(__x86_64__)
  #include "H5Tinit_Linux_x86_64.ic"
  #else
  #include "H5Tinit_Linux.ic"
  #endif

#else

  #error "Unknown platform."

#endif
