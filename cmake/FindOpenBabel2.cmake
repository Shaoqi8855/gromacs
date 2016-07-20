# - Find OPENBABEL2
# Find the OpenBabel version 2 library.
#
#  OPENBABEL2_INCLUDE_DIR - where to find openbabel/obconversion.h
#  OPENBABEL2_LIBRARIES   - List of libraries when using OPENBABEL2
#  OPENBABEL2_FOUND       - True if OPENBABEL2 was found

if(OPENBABEL2_INCLUDE_DIR)
  # Already in cache, be silent
  set(OPENBABEL2_FIND_QUIETLY TRUE)
endif(OPENBABEL2_INCLUDE_DIR)

if(NOT OPENBABEL2_INCLUDE_DIR)
  find_path(OPENBABEL2_INCLUDE_DIR openbabel-2.0/openbabel/obconversion.h
    PATHS
    ${_obIncDir}
    ${GNUWIN32_DIR}/include
    $ENV{OPENBABEL2_INCLUDE_DIR}
  )
  if(OPENBABEL2_INCLUDE_DIR)
    set(OPENBABEL2_INCLUDE_DIR ${OPENBABEL2_INCLUDE_DIR}/openbabel-2.0 CACHE INTERNAL "OpenBabel2 include directory")
  endif(OPENBABEL2_INCLUDE_DIR)
endif(NOT OPENBABEL2_INCLUDE_DIR)

find_library(OPENBABEL2_LIBRARIES NAMES openbabel openbabel-2
  PATHS
  ${_obLinkDir}
  ${GNUWIN32_DIR}/lib
  $ENV{OPENBABEL2_LIBRARIES}
)

# handle the QUIETLY and REQUIRED arguments and set OPENBABEL2_FOUND to TRUE if
# all listed variables are TRUE
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (OPENBABEL2 DEFAULT_MSG OPENBABEL2_LIBRARIES OPENBABEL2_INCLUDE_DIR)

mark_as_advanced (OPENBABEL2_LIBRARIES OPENBABEL2_INCLUDE_DIR)