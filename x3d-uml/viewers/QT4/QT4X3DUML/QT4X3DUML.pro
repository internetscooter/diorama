# -------------------------------------------------
# Project created by QtCreator 2009-08-04T10:10:01
# -------------------------------------------------
QT += opengl
TARGET = QT4X3DUML
TEMPLATE = app
INCLUDEPATH = D:\OpenSceneGraph-2.8.0\include
win32:LIBS += "D:\OpenSceneGraph-2.8.0\lib\osg.lib" \
    "D:\OpenSceneGraph-2.8.0\lib\osgViewer.lib" \
    "D:\OpenSceneGraph-2.8.0\lib\OpenThreads.lib" \
    "D:\OpenSceneGraph-2.8.0\lib\osgGA.lib" \
    "D:\OpenSceneGraph-2.8.0\lib\osgDB.lib" \
    "D:\OpenSceneGraph-2.8.0\lib\osgUtil.lib" \
    "D:\OpenSceneGraph-2.8.0\lib\osgManipulator.lib" \
    "D:\OpenSceneGraph-2.8.0\lib\osgText.lib"
SOURCES += main.cpp \
    x3dumlqt.cpp
HEADERS += x3dumlqt.h
FORMS += 
