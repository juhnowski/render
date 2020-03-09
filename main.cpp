#include <iostream>
#include "filesystem_before17"

using namespace std;

int main(int argc, char **argv) {
    if(argc!=2) {
        cout << "Usage: render <configure.ini>" << endl;
        return 1;
    }

    const string& dir {argv[1]};

    if(!exists(dir)){
        cout << "Path " << dir << " does not exist." << endl;
        return 1;
    }

    cout << "Received ini file: "<< argv[1] << endl;
    return 0;
}
