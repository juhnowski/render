//
// Created by ilya on 10.03.2020.
//

#include "Actor.h"
#include "before17.h"
#include "easylogging++.h"
#include "fmt/core.h"
#include "constants.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <thread>

Actor::Actor(Settings *settings) {
    this->settings = settings;
};

int Actor::prepare() {

    if (!exists(settings->script_file)) {
        LOG(ERROR) << "Render did not start. Template script file " << settings->script_file << " does not exist."
                   << endl;
        return 1;
    }


    ifstream t(settings->script_file);
    stringstream sh_template;
    sh_template << t.rdbuf();

    if (settings->script_type.compare(ACTION_FFMPEG) == 0) {
        this->cmd = fmt::format(
                sh_template.str(),
                settings->rtp_sdp,
                settings->rtmp_url);
    } else if (settings->script_type.compare(ACTION_GSTREAMER) == 0) {
        this->cmd = fmt::format(
                sh_template.str(),
                settings->rtp_audio_port,
                settings->rtp_video_port,
                settings->rtmp_url
        );
    } else if (settings->script_type.compare(ACTION_TEST) == 0) {
        this->cmd = sh_template.str();
    } else {
        LOG(ERROR) << "Render did not start. Unsupported script type:" << settings->script_type;
        return 1;
    }
    LOG(DEBUG) << "Prepared:" << endl << this->cmd;

    return 0;
}

int Actor::start() {
//    thread t(&Actor::thread_function, this);
//    LOG(DEBUG) << "Renderer started";
//    t.join();
    return this->system_start();
};

int Actor::stop() {
    return 0;
};

int Actor::system_start() {
    int status;

    switch (this->pid = fork()) {
        case -1:
            return -1;
        case 0:
            system(this->cmd.c_str());
        default:
            if (waitpid(this->pid, &status, 0) == -1)
                return -1;
            else
                return status;
    }
}