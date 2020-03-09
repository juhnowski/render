Render

Программа для рендеринга rtp -> rtmp

# Настройки
Все настройки лежат в configure.ini
```[common]``` 

```Log = logging.conf``` - логгирование настраивается отдельным конфигурационным файлом.
[Описание формат файла](https://github.com/amrayn/easyloggingpp) 
 
```WorkDir = /tmp``` - рабочий каталог

[rtp]
sdp = test.sdp
; используется в ffmpeg.tsh

[rtp.audio]
port = 11111
; используется в gstreamer.tsh

[rtp.video]
port = 11111
; используется в gstreamer.tsh

[rtmp]
url = rtmp://gpu3.view.me/live/obsl-test32

[script]
file = gstreamer.tsh
;file=ffmpeg.tsh

# Логирование
Конфигурационный файл для логов указывается в секции common параметр Log.
До того как будет прочтен файл конфигурации, логирование по умолчанию производится 
в /var/log/syslog