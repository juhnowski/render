#include <iostream>
#include "filesystem_before17.h"
#include "Settings.h"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "Usage: render <configure.ini>" << endl;
        return 1;
    }

    const string &ini_filename{argv[1]};

    if (!exists(ini_filename)) {
        cout << "File " << ini_filename << " does not exist." << endl;
        return 1;
    }

    cout << "Received ini file: " << argv[1] << endl;

    Settings *settings = new Settings();
    settings->parse(ini_filename);

    cout << *settings;

    return 0;
}
