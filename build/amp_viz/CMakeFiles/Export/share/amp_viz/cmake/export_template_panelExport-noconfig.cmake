#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "amp_viz::template_panel" for configuration ""
set_property(TARGET amp_viz::template_panel APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(amp_viz::template_panel PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libtemplate_panel.so"
  IMPORTED_SONAME_NOCONFIG "libtemplate_panel.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS amp_viz::template_panel )
list(APPEND _IMPORT_CHECK_FILES_FOR_amp_viz::template_panel "${_IMPORT_PREFIX}/lib/libtemplate_panel.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
