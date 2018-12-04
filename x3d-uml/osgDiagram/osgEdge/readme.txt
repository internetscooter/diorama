These files get added to the osg directory and built as part of the OpenSceneGraph build.

Eventually this will be submitted as a new feature but for now we'll just do it manually

Here are the steps.

1) Copy the header files to D:\OpenSceneGraph-2.8.0\include\osg (or your equivalent)
2) Copy the cpp files to D:\OpenSceneGraph-2.8.0\src\osg (or your equivalent)
3) Add the files to the osg project and rebuild


Concepts:


Edge			- connects two objects with a line
EdgeTriangle		- connects two objects with a transparent triangle (to indicate parent child relationships)
EdgeUpdateCallback	- allows lines to be dynamic and move with the objects they are connected to

Known issues:

EdgeTriangle.cpp is a bit of a hack. It works for state machines diagrams due to know what they
should appear like. Ideally EdgeTriangle should calculated the width of an object in relation
to the point where the base of the triang should meet. i.e. should be made to work for all shapes and
situations.


A code snippet that may help:

	osg::ref_ptr<osg::EdgeTriangle> line_edge2 = new osg::EdgeTriangle(theStateView->geode.get(), topStatePerimeter->geode.get());
	osg::ref_ptr<osg::MatrixTransform> spinTrans = new osg::MatrixTransform;
	mRoot->addChild(line_edge2.get()); // *** NOTE *** issues with line edges due to spinning
	// stuff around. Line edges are based on world coords, so there is a problem with associating
	// an edge with a geode as we don't know which way up it will be
	// had to hack the edge implementation to work for now but it won't work generically for 
	// "un-spun" worlds :(