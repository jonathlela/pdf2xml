#include <stdio.h>
#include "libxml/parser.h"

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
	void pdftoxmlFileWithOptions(const char *filename, FILE* file, const char  *ownerPassword, const char *userPassword, int firstPage, int lastPage, const char *namespaceURI);

	/** Convert PDF file to XML
	 * @param filename The PDF file name
	 * @param file The XML output file
	 */
	void pdftoxmlFile(const char*filename, FILE* file);

	/** Convert PDF file to XML
	 * @param filename The PDF file name
	 * @param parser the XML push parser context
	 * @param ownerPassword The PDF owner password if needed
	 * @param userPassword The PDF user password if needed
	 * @param firstPage The first page to convert
	 * @param lastPage The last page to convert
	 * @param namespaceURI The namespace URI if it specified
	 */
	void pdftoxmlParserWithOptions(const char *filename, xmlParserCtxtPtr parser, const char  *ownerPassword, const char *userPassword, int firstPage, int lastPage, const char *namespaceURI);

	/** Convert PDF file to XML
	 * @param parser the XML push parser context
	 * @param file The XML output file
	 */
	void pdftoxmlParser(const char*filename, xmlParserCtxtPtr parser);

}
