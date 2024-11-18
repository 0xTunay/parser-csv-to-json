#include <XLConstants.hpp>

using namespace OpenXLSX;

int main(void) {

    XLDocument doc;
    doc.create("Spreadsheet.xlsx");
    auto wks = doc.workbook().worksheet("Sheet1");

    wks.cell("A1").value() = "Hello, OpenXLSX!";

    doc.save();

    return 0;
}