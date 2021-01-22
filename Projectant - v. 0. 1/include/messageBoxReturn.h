#ifndef MESSAGEBOXRETURN_H
#define MESSAGEBOXRETURN_H

#include <windows.h>
#include "jate.h"

using namespace std;

LPCSTR testr = "\t\tMIT License\n\nCopyright (c) 2021 MitasVit\n\nPermission is hereby granted, free of charge, to any person obtaining a copy\nof this software and associated documentation files (the \"Software\"), to deal\nin the Software without restriction, including without limitation the rights\nto use, copy, modify, merge, publish, distribute, sublicense, and/or sell\ncopies of the Software, and to permit persons to whom the Software is\nfurnished to do so, subject to the following conditions:\n\nThe above copyright notice and this permission notice shall be included in all\ncopies or substantial portions of the Software.\n\nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\nIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\nFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\nAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\nLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\nOUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\nSOFTWARE.";

void Boxe(){
    ifstream boxeso("C:/projectant/data/submit.r");
    if(boxeso.is_open()){
        boxeso.close();
    }else{
        MessageBox(NULL,testr,"Submit license", MB_OK| MB_SERVICE_NOTIFICATION | MB_ICONQUESTION);
        ofstream bohes("C:/projectant/data/submit.r");
        bohes.close();
    }
}
int Boxes()
{


    int msgboxID = MessageBox(NULL,testr,"Submit license", MB_OK| MB_SERVICE_NOTIFICATION | MB_ICONQUESTION);

    switch (msgboxID)
    {
    case IDOK:
        {
           // TODO: add code
        cout << "lop";
        break;
        }
    default:
    {
        return msgboxID;
        break;
    }


}
return msgboxID;
}


#endif // MESSAGEBOXRETURN_H
