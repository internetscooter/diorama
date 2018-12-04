#ifndef X3DUMLQT_H
#define X3DUMLQT_H

// OpenSceneGraph files - set INCLUDEPATH in pro file to your local source
#include <osg/Referenced>
#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>

#include <QGLWidget>
#include <QtCore/QString>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>
#include <QtGui/QApplication>
#include <QtOpenGL/QGLWidget>
#include <QtGui/QMainWindow>
//#include <QtGui/QMdiSubWindow>
//#include <QtGui/QMdiArea>

using Qt::WindowFlags;


class X3DUMLQT : public QGLWidget
{
    Q_OBJECT
public:
    X3DUMLQT();
    //X3DUMLQT( QWidget * parent = 0, const char * name = 0, const QGLWidget * shareWidget = 0, WindowFlags f = 0 );

    virtual ~X3DUMLQT() {}

    osgViewer::GraphicsWindow* getGraphicsWindow() { return _gw.get(); }
    const osgViewer::GraphicsWindow* getGraphicsWindow() const { return _gw.get(); }

protected:

    void init();

    virtual void resizeGL( int width, int height );
    virtual void keyPressEvent( QKeyEvent* event );
    virtual void keyReleaseEvent( QKeyEvent* event );
    virtual void mousePressEvent( QMouseEvent* event );
    virtual void mouseReleaseEvent( QMouseEvent* event );
    virtual void mouseMoveEvent( QMouseEvent* event );
    virtual void wheelEvent(QWheelEvent *event);
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _gw;
};

#endif // X3DUMLQT_H




