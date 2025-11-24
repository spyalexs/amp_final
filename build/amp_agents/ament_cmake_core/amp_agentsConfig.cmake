# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_amp_agents_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED amp_agents_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(amp_agents_FOUND FALSE)
  elseif(NOT amp_agents_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(amp_agents_FOUND FALSE)
  endif()
  return()
endif()
set(_amp_agents_CONFIG_INCLUDED TRUE)

# output package information
if(NOT amp_agents_FIND_QUIETLY)
  message(STATUS "Found amp_agents: 0.0.0 (${amp_agents_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'amp_agents' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${amp_agents_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(amp_agents_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${amp_agents_DIR}/${_extra}")
endforeach()
