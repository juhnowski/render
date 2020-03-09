#include <iostream>
#include "filesystem_before17.h"
#include "Settings.h"
#include "easylogging++.h"

using namespace std;

INITIALIZE_EASYLOGGINGPP

int main(int argc, char **argv) {

    el::Configurations syslogConf;
    syslogConf.setToDefault();
    syslogConf.set(el::Level::Error, el::ConfigurationType::Format, "%datetime %level %msg");
    el::Loggers::reconfigureLogger("default", syslogConf);

    if (argc != 2) {
        LOG(ERROR) << "Render did not start. Usage: render <configure.ini>";
        return 1;
    }

    const string &ini_filename{argv[1]};

    if (!exists(ini_filename)) {
        LOG(ERROR) << "Render did not start. File " << ini_filename << " does not exist." << endl;
        return 1;
    }

    Settings *settings = new Settings();
    settings->parse(ini_filename);

    el::Configurations conf(settings->log);
    el::Loggers::reconfigureAllLoggers(conf);

    LOG(INFO) << "Render started";
    LOG(DEBUG) << *settings;


    return 0;
}
