#========================================================================
#
# pdftoxml Makefile
#
# author: Sophie Andrieu, Herve Dejean
# Xerox Research Centre Europe
# (c) cpry XRCE 2007
#
#========================================================================

ifdef DEBUG
CFLAGS=-Wall -O0 -ggdb
else
CFLAGS=-Wall -O3
endif

CXXFLAGS=$(CFLAGS)

LIBPROG=ar
DEL=rm

# Directories
DIRSRC=src
DIREXE=bin


# Executable name
PDFTOXMLEXE=pdftoxml

# Main target
all: pdftoxmlEXE

compile.src:
	$(CXX) $(CXXFLAGS) -o $(DIRSRC)/ConstantsUtils.o -c $(DIRSRC)/ConstantsUtils.cc
	$(CXX) $(CXXFLAGS) -o $(DIRSRC)/ConstantsXML.o -c $(DIRSRC)/ConstantsXML.cc
	$(CXX) $(CXXFLAGS) `pkg-config --cflags poppler libxml-2.0` -o $(DIRSRC)/Parameters.o -c $(DIRSRC)/Parameters.cc
	$(CXX) $(CXXFLAGS) `pkg-config --cflags poppler libxml-2.0` -o $(DIRSRC)/AnnotsXrce.o -c $(DIRSRC)/AnnotsXrce.cc
	$(CXX) $(CXXFLAGS) `pkg-config --cflags poppler libxml-2.0` -o $(DIRSRC)/PDFDocXrce.o -c $(DIRSRC)/PDFDocXrce.cc
	$(CXX) $(CXXFLAGS) `pkg-config --cflags poppler libxml-2.0 glib-2.0` -o $(DIRSRC)/XmlOutputDev.o -c $(DIRSRC)/XmlOutputDev.cc
	$(AR) -rc $(DIRSRC)/libxml2pdf.a $(DIRSRC)/ConstantsUtils.o $(DIRSRC)/ConstantsXML.o $(DIRSRC)/Parameters.o $(DIRSRC)/AnnotsXrce.o $(DIRSRC)/PDFDocXrce.o $(DIRSRC)/XmlOutputDev.o

# Target to create the executable for pdftoxml (locate in exe directory)
pdftoxmlEXE: compile.src
	mkdir -p $(DIREXE)
	$(CXX) $(CXXFLAGS) `pkg-config --cflags poppler` -o $(DIRSRC)/parseargs.o -c $(DIRSRC)/parseargs.cc
	$(CXX) $(CXXFLAGS) `pkg-config --cflags poppler libxml-2.0 glib-2.0` -o $(DIRSRC)/pdftoxml.o -c $(DIRSRC)/pdftoxml.cc
	$(CXX) $(CXXFLAGS) `pkg-config --cflags --libs poppler libxml-2.0 glib-2.0` -o $(DIREXE)/$(PDFTOXMLEXE) $(DIRSRC)/parseargs.o $(DIRSRC)/pdftoxml.o $(DIRSRC)/libxml2pdf.a



# Clean target to delete all .o files, .a files library and .exe files
clean:
	$(RM) $(DIRSRC)/libxml2pdf.a
	$(RM) $(DIRSRC)/*.o
	$(RM) $(DIREXE)/*
