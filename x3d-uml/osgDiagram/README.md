Very Very Very Old X3D-UML Code
===============================

This is just here for reference but shouldn't be "that" hard to bring back to life.

osg is OpenSceneGraph [http://www.openscenegraph.org/] which abstracts OpenGL in to a scenegraph and provides some viewers that can be included in various applications framworks (e.g. QT). osgDiagram is an extension to osg to enable 3D diagrams.

The rebirth process would be to:

- build the latest osg
- build this extension against that 
- get the osg viewer working and include the osdDiagram plugin

To create diagrams you need to do this in code. The plugin also allows the diagrams to be manipulated in space.

I am very sorry that I did not create CMAKE build scripts for this!

original readme.txt
===================

Extension to osg (OpenSceneGraph) to enable interactive 3D diagrams.

Based on the UML Diagram Interchange Specification (but will be extended further in future).

This project is initially based on Visual Studio 2008 (since a requirement was to integrate
to a Windows UML tool). Here are some settings you should be aware of...

1) You need to include the following paths, where "X" is the drive name.

This should be the standard place where osg is built

X:\OpenSceneGraph-2.6.1\include
X:\OpenSceneGraph-2.6.1\lib


