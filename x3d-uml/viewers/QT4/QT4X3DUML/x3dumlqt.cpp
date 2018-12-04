#include "x3dumlqt.h"

//X3DUMLQT::X3DUMLQT( QWidget * parent, const char * name, const QGLWidget * shareWidget, WindowFlags f):
//    QGLWidget(parent, shareWidget, f)
    X3DUMLQT::X3DUMLQT()
{
   // _gw = new osgViewer::GraphicsWindowEmbedded(0,0,width(),height());
   // setFocusPolicy(Qt::ClickFocus);
}

void X3DUMLQT::resizeGL( int width, int height )
{
//    _gw->getEventQueue()->windowResize(0, 0, width, height );
//    _gw->resized(0,0,width,height);
}

void X3DUMLQT::keyPressEvent( QKeyEvent* event )
{
//    _gw->getEventQueue()->keyPress( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toAscii().data() ) );
}

void X3DUMLQT::keyReleaseEvent( QKeyEvent* event )
{
//    _gw->getEventQueue()->keyRelease( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toAscii().data() ) );
}

void X3DUMLQT::mousePressEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
 //   _gw->getEventQueue()->mouseButtonPress(event->x(), event->y(), button);
}

void X3DUMLQT::mouseReleaseEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
  //  _gw->getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);
}

void X3DUMLQT::mouseMoveEvent( QMouseEvent* event )
{
 //   _gw->getEventQueue()->mouseMotion(event->x(), event->y());
}

void X3DUMLQT::wheelEvent(QWheelEvent *event)
{
//    _gw->getEventQueue()->mouseScroll((event->delta()>0) ?
 //           osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN);
}
