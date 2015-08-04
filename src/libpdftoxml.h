#include <stdio.h>

extern "C" {

	/** Convert PDF file to XML
	 * @param filename The PDF file name
	 * @param file The XML output file
	 * @param ownerPassword The PDF owner password if needed
	 * @param userPassword The PDF user password if needed
	 * @param firstPage The first page to convert
	 * @param lastPage The last page to convert
	 * @param namespaceURI The namespace URI if it specified
	 */
	void pdftoxmlWithOptions(const char *filename, FILE* file, const char  *ownerPassword, const char *userPassword, int firstPage, int lastPage, const char *namespaceURI);

	/*
	/** Convert PDF file to XML
	 * @param filename The PDF file name
	 * @param file The XML output file
	**/
	void pdftoxml(const char*filename, FILE* file);

}
