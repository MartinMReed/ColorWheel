# Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR =  $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/BrightnessBarView.cpp) \
                 $$quote($$BASEDIR/src/ColorPickerView.cpp) \
                 $$quote($$BASEDIR/src/ColorWheelApp.cpp) \
                 $$quote($$BASEDIR/src/ColorWheelView.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/BrightnessBarView.h) \
                 $$quote($$BASEDIR/src/ColorPickerView.h) \
                 $$quote($$BASEDIR/src/ColorWheelApp.h) \
                 $$quote($$BASEDIR/src/ColorWheelView.h)
    }

    CONFIG(release, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/BrightnessBarView.cpp) \
                 $$quote($$BASEDIR/src/ColorPickerView.cpp) \
                 $$quote($$BASEDIR/src/ColorWheelApp.cpp) \
                 $$quote($$BASEDIR/src/ColorWheelView.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/BrightnessBarView.h) \
                 $$quote($$BASEDIR/src/ColorPickerView.h) \
                 $$quote($$BASEDIR/src/ColorWheelApp.h) \
                 $$quote($$BASEDIR/src/ColorWheelView.h)
    }
}

simulator {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/BrightnessBarView.cpp) \
                 $$quote($$BASEDIR/src/ColorPickerView.cpp) \
                 $$quote($$BASEDIR/src/ColorWheelApp.cpp) \
                 $$quote($$BASEDIR/src/ColorWheelView.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/BrightnessBarView.h) \
                 $$quote($$BASEDIR/src/ColorPickerView.h) \
                 $$quote($$BASEDIR/src/ColorWheelApp.h) \
                 $$quote($$BASEDIR/src/ColorWheelView.h)
    }
}

INCLUDEPATH +=  $$quote($$BASEDIR/src)

lupdate_inclusion {
    SOURCES +=  $$quote($$BASEDIR/../src/*.c) \
             $$quote($$BASEDIR/../src/*.c++) \
             $$quote($$BASEDIR/../src/*.cc) \
             $$quote($$BASEDIR/../src/*.cpp) \
             $$quote($$BASEDIR/../src/*.cxx) \
             $$quote($$BASEDIR/../assets/*.qml) \
             $$quote($$BASEDIR/../assets/*.js) \
             $$quote($$BASEDIR/../assets/*.qs)

    HEADERS +=  $$quote($$BASEDIR/../src/*.h) \
             $$quote($$BASEDIR/../src/*.h++) \
             $$quote($$BASEDIR/../src/*.hh) \
             $$quote($$BASEDIR/../src/*.hpp) \
             $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS =  $$quote($${TARGET}.ts)
