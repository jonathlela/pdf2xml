set(common_srcs
  parseargs.cc
)

set(lib_srcs
  ConstantsUtils.cc
  ConstantsXML.cc
  Parameters.cc
  AnnotsXrce.cc
  PDFDocXrce.cc
  XmlOutputDev.cc
  libpdftoxml.cc
)

set(lib_includes
  ConstantsUtils.h
  ConstantsXML.h
  Parameters.h
  AnnotsXrce.h
  PDFDocXrce.h
  XmlOutputDev.h
  pdftoxml.h
)

include_directories(${GLIB2_INCLUDE_DIRS} ${LIBXML2_INCLUDE_DIR} ${POPPLER_INCLUDE_DIRS})

add_definitions(${LIBXML2_DEFINITIONS})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -ggdb")

# pdftoxml library
add_library(libpdftoxml STATIC ${lib_srcs})
set_target_properties(libpdftoxml PROPERTIES OUTPUT_NAME "pdftoxml"
                                             PUBLIC_HEADER "${lib_includes}")

add_library(libpdftoxmlShared SHARED ${lib_srcs})
set_target_properties(libpdftoxmlShared PROPERTIES OUTPUT_NAME "pdftoxml"
                                                   SOVERSION 1
												   VERSION 1.0.0
                                                   PUBLIC_HEADER "${lib_includes}")

# pdftoxml executable
set(pdftoxml_SOURCES ${common_srcs}
  pdftoxml.cc
)

add_executable(pdftoxml ${pdftoxml_SOURCES})

target_link_libraries(pdftoxml LINK_PUBLIC libpdftoxml ${GLIB2_LIBRARIES} ${LIBXML2_LIBRARIES} ${POPPLER_LIBRARIES})

install(TARGETS pdftoxml libpdftoxml libpdftoxmlShared
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)
