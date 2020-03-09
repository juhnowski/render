//
// Created by ilya on 09.03.2020.
//

#ifndef RENDER_SETTINGS_H
#define RENDER_SETTINGS_H

#include <string>
#include <iostream>

using namespace std;

class Settings {
public:
    string log;
    string work_dir;

    string rtp_sdp;
    int rtp_audio_port;
    int rtp_video_port;

    string rtmp_url;

    string script_file;

    void parse(const string &ini_filename);

    friend ostream &operator<<(ostream &_stream, Settings const &s) {
        _stream << "Settings:" << endl
                << "\t[" << endl
                << "\t\tlog=" << s.log << endl
                << "\t\twork_dir=" << s.work_dir << endl
                << "\t\trtp_sdp=" << s.rtp_sdp << endl
                << "\t\trtp_audio_port=" << s.rtp_audio_port << endl
                << "\t\trtp_video_port=" << s.rtp_video_port << endl
                << "\t\trtmp_url=" << s.rtmp_url << endl
                << "\t\tscript_file=" << s.script_file << endl
                << "\t]" << endl
                << endl;
    }
};


#endif //RENDER_SETTINGS_H
