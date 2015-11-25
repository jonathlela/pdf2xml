cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)

project (pdftoxml)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules")
find_package(LibXml2 REQUIRED)
find_package(Poppler REQUIRED)
find_package(GLIB2 REQUIRED)
find_package(PNG REQUIRED)

add_subdirectory(src)
