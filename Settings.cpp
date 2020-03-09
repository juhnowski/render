//
// Created by ilya on 09.03.2020.
//

#include "Settings.h"
#include <iostream>
#include <fstream>
#include "ini.h"
#include "easylogging++.h"

using namespace std;

void Settings::parse(const string &ini_filename) {

    ini::Ini<char> ini;
    ifstream is(ini_filename);
    ini.parse(is);

    ini::extract(ini.sections["common"]["Log"], log);
    ini::extract(ini.sections["common"]["WorkDir"], work_dir);
    ini::extract(ini.sections["rtp"]["sdp"], rtp_sdp);
    ini::extract(ini.sections["rtp.audio"]["port"], rtp_audio_port);
    ini::extract(ini.sections["rtp.video"]["port"], rtp_video_port);
    ini::extract(ini.sections["rtmp"]["url"], rtmp_url);
    ini::extract(ini.sections["script"]["file"], script_file);
}