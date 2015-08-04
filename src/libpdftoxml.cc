#include "XmlOutputDev.h"
#include "PDFDocXrce.h"
#include "libxml/xmlIO.h"
#include "libpdftoxml.h"

void pdftoxmlWithOptions(const char *filename, FILE* file, const char  *ownerPassword, const char *userPassword, int firstPage, int lastPage, const char *namespaceURI) {
	PDFDocXrce *doc;
	GooString *ownerPW = NULL;
	GooString *userPW = NULL;
	GooString *nsURI = NULL;
	GooString *fileName = NULL;
	XmlOutputDev *xmlOut;
	GBool physLayout = gTrue;
	GBool verbose = gFalse;

	xmlOutputBufferPtr output;
	output = xmlOutputBufferCreateFile(file, NULL);
	
	parameters = new Parameters();
	globalParams = new GlobalParams(NULL);
	
	if (ownerPassword) {
		ownerPW = new GooString(ownerPassword);
	}
	if (userPassword) {
		userPW = new GooString(userPassword);
	}

	if (namespaceURI) {
		nsURI = new GooString(namespaceURI);
	}

	fileName = new GooString(filename);
	
	doc = new PDFDocXrce(fileName, ownerPW, userPW);

	if (userPW) {
		delete userPW;
	}
	if (ownerPW) {
		delete ownerPW;
	}
	
	xmlOut = new XmlOutputDev(output ,fileName, doc->getCatalog(), physLayout, verbose, nsURI);

	int first = firstPage;
	int last = lastPage;

   	if (first < 1) {
   		first = 1;
   	}
	if (last < 1 || last > doc->getNumPages()) {
		last = doc->getNumPages();
	}
	
	
	if (xmlOut->isOk()) {
		doc->displayPages(xmlOut, NULL, first, last, 72, 72, 0, gTrue, gTrue, gFalse);
	}

	if (nsURI) {
		delete nsURI;
	}

	delete xmlOut;
	delete doc;
	delete parameters;
}

void pdftoxml(const char*filename, FILE* file) {
	return pdftoxmlWithOptions(filename, file, NULL, NULL, 0, 0, NULL);
}
