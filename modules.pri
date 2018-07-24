split_modules = $$split(MODULE, .)
module_name = $$last(split_modules)
join_path = $$join(split_modules, /)
CONFIG(debug, debug|release) {
    build_type = debug
} else {
    build_type = release
}
target_path = $$ROOT_DIR/$$join_path/$$build_type

for(item, DEPEND_MODULES) {
    split_modules = $$split(item, .)
    module_name = $$last(split_modules)
    join_modules = $$join(split_modules, /)
    #message($$ROOT_DIR/$$join_modules/$$build_type)

    LIBS += -L$$ROOT_DIR/$$join_modules/$$build_type -l$$module_name

    linux-g++{
        #QMAKE_POST_LINK += $$quote(cp $$join $${DESTDIR}$$escape_expand(\n\t))
    }

    win32 {
        #QMAKE_POST_LINK += $$quote(cmd /c copy /Y $$ROOT_DIR/$$join_modules/$$build_type/$$module_name $${BUILD_DIR}$$escape_expand(\n\t))
    }
}

contains(TEMPLATE, lib) {
    win32 {
        extension = .dll
    }
    linux-g++ {
        extension = .so
    }
} else {
    win32 {
        extension = .exe
    }
}
target_file = $$OUT_PWD/$$build_type/$${TARGET}$${extension}
win32 {
    target_file = $$replace(target_file, /, \\)
}
win32 {
    QMAKE_POST_LINK += $$quote(cmd /C copy /Y $$target_file $${BUILD_DIR}$$escape_expand(\n\t))
}
