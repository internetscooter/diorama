#include <osg/Edge>
#include <osg/LineWidth>
#include <osg/EdgeUpdateCallback>

#include <iostream>

using namespace osg;



Edge::Edge()
{
	//osg::Geometry* lineGeom = new osg::Geometry();
 //   osg::Vec3Array* vertices = new osg::Vec3Array(2);
 //   vertices->push_back(osg::Vec3(0.0, 0.0, 0.0));
 //   vertices->push_back(osg::Vec3(2.0, 0.0, 0.0));
	//lineGeom->setVertexArray(vertices);
	//lineGeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP,0,vertices->getNumElements()));
	//	// set the colors a
 //   osg::Vec4Array* colors = new osg::Vec4Array;
 //   colors->push_back(osg::Vec4(0.0f,0.0f,0.0f,1.0f)); //black
 //   lineGeom->setColorArray(colors);
 //   lineGeom->setColorBinding(osg::Geometry::BIND_OVERALL);
	//osg::StateSet* lineState = lineGeom->getOrCreateStateSet();
	//osg::LineWidth* lineWidth = new osg::LineWidth(2.0);
	//lineState->setAttribute(lineWidth);
	//this->addDrawable(lineGeom);
}
Edge::Edge(Geode* startNode, Geode* endNode)
{
	_startNode = startNode;
	_endNode = endNode;

	// find _startNode centre
	osg::MatrixList _startNodeWorldMatrices = _startNode->getWorldMatrices();
	osg::Vec3 _startNodeCenter;
	for(osg::MatrixList::iterator itr = _startNodeWorldMatrices.begin();
       itr != _startNodeWorldMatrices.end();
       ++itr)
	{
		osg::Matrix& matrix = *itr;
		_startNodeCenter = _startNode->getBound().center() * matrix;
	}

	// find _endNode centre
	osg::MatrixList _endWorldMatrices = _endNode->getWorldMatrices();
	osg::Vec3 _endNodeCenter;

	for(osg::MatrixList::iterator itr = _endWorldMatrices.begin();
       itr != _endWorldMatrices.end();
       ++itr)
	{
		osg::Matrix& matrix = *itr;
		_endNodeCenter = _endNode->getBound().center() * matrix;
	}

	//osg::BoundingBox bbStart = _startNode->getBoundingBox();
	//osg::BoundingBox bbEnd = _endNode->getBoundingBox();

	_lineGeom = new osg::Geometry();
    _vertices = new osg::Vec3Array();
    //vertices->push_back(osg::Vec3(0.0, 0.0, 0.0));
    //vertices->push_back(osg::Vec3(2.0, 0.0, 0.0));
    //_vertices->push_back(bbStart.center());
    //_vertices->push_back(bbEnd.center());
    _vertices->push_back(_startNodeCenter);
    _vertices->push_back(_endNodeCenter);

	//(*vertices)[0].set(bbStart.center());
	//(*vertices)[1].set(bbEnd.center());

	_lineGeom->setVertexArray(_vertices);
	_lineGeom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP,0,_vertices->getNumElements()));
		// set the colors a
    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(0.0f,0.0f,0.0f,1.0f)); //black
    _lineGeom->setColorArray(colors);
    _lineGeom->setColorBinding(osg::Geometry::BIND_OVERALL);
	osg::StateSet* lineState = _lineGeom->getOrCreateStateSet();
	osg::LineWidth* lineWidth = new osg::LineWidth(2.0);
	lineState->setAttribute(lineWidth);
	this->addDrawable(_lineGeom);
	this->setDataVariance(osg::Object::DYNAMIC);
	this->setUpdateCallback(new EdgeUpdateCallback);
}

void Edge::EdgeUpdate()
{
	if (_startNode != NULL)
	{
		// find _startNode centre
		osg::MatrixList _startNodeWorldMatrices = _startNode->getWorldMatrices();
		osg::Vec3 _startNodeCenter;
		for(osg::MatrixList::iterator itr = _startNodeWorldMatrices.begin();
		   itr != _startNodeWorldMatrices.end();
		   ++itr)
		{
			osg::Matrix& matrix = *itr;
			_startNodeCenter = _startNode->getBound().center() * matrix;
		}

		// find _endNode centre
		osg::MatrixList _endWorldMatrices = _endNode->getWorldMatrices();
		osg::Vec3 _endNodeCenter;

		for(osg::MatrixList::iterator itr = _endWorldMatrices.begin();
		   itr != _endWorldMatrices.end();
		   ++itr)
		{
			osg::Matrix& matrix = *itr;
			_endNodeCenter = _endNode->getBound().center() * matrix;
		}

		(*_vertices)[0].set(_startNodeCenter);
		(*_vertices)[1].set(_endNodeCenter);

		_lineGeom->setVertexArray(_vertices);
		_lineGeom->setPrimitiveSet(0,new osg::DrawArrays(osg::PrimitiveSet::LINE_STRIP,0,_vertices->getNumElements()));
			// set the colors a
		osg::Vec4Array* colors = new osg::Vec4Array;
		colors->push_back(osg::Vec4(0.0f,0.0f,0.0f,1.0f)); //black
		_lineGeom->setColorArray(colors);
		_lineGeom->setColorBinding(osg::Geometry::BIND_OVERALL);
		osg::StateSet* lineState = _lineGeom->getOrCreateStateSet();
		osg::LineWidth* lineWidth = new osg::LineWidth(2.0);
		lineState->setAttribute(lineWidth);
		this->addDrawable(_lineGeom);
	}



}