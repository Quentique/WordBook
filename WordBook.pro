######################################################################
# Automatically generated by qmake (3.0) dim. sept. 28 20:29:10 2014
######################################################################

TEMPLATE = app
TARGET = WordBook
INCLUDEPATH += C:\Qt\5.3\mingw482_32\include\poppler-qt5
LIBS += -LC:\Qt\5.3\mingw482_32\poppler\lib\ -lpopplerqt5
QT += gui widgets core xml webkitwidgets printsupport
# Input
HEADERS += aide.h ajout.h fenetre.h modifier.h option.h propos.h style.h web.h
SOURCES += aide.cpp \
           ajout.cpp \
           fenetre.cpp \
           main.cpp \
           modifier.cpp \
           option.cpp \
           propos.cpp \
           style.cpp \
           web.cpp
RESOURCES += ressources.qrc
TRANSLATIONS += langue_en.ts langue_de.ts

RC_FILE += ressources.rc
