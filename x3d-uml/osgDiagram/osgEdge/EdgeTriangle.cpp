#include <osg/EdgeTriangle>
#include <osg/LineWidth>
#include <osg/EdgeUpdateCallback>
#include <osg/BlendFunc>

#include <iostream>

using namespace osg;



EdgeTriangle::EdgeTriangle()
{
}
EdgeTriangle::EdgeTriangle(Geode* startNode, Geode* endNode)
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

	_lineGeom = new osg::Geometry();
    _vertices = new osg::Vec3Array();

    //vertices->push_back(osg::Vec3(0.0, 0.0, 0.0));
    //vertices->push_back(osg::Vec3(2.0, 0.0, 0.0));
    //_vertices->push_back(bbStart.center());
    //_vertices->push_back(bbEnd.center());
    _vertices->push_back(_startNodeCenter);

	osg::BoundingBox bbEnd = _endNode->getBoundingBox();

    _vertices->push_back(osg::Vec3(_endNodeCenter.x(), _endNodeCenter.y() + bbEnd.yMin(), _endNodeCenter.z()));
    _vertices->push_back(osg::Vec3(_endNodeCenter.x(), _endNodeCenter.y() - bbEnd.yMax(), _endNodeCenter.z()));

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

void EdgeTriangle::EdgeUpdate()
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
    //_vertices->push_back(_startNodeCenter);
    //_vertices->push_back(osg::Vec3(_endNodeCenter.x() + 20, _endNodeCenter.y(), _endNodeCenter.z()));
    //_vertices->push_back(osg::Vec3(0.0, 0.0, 0.0)_endNodeCenter);

		(*_vertices)[0].set(_startNodeCenter);

			osg::BoundingBox bbEnd = _endNode->getBoundingBox();

		//(*_vertices)[1].set(osg::Vec3(_endNodeCenter.x() + bbEnd.xMin(), _endNodeCenter.y(), _endNodeCenter.z()));
		//(*_vertices)[2].set(osg::Vec3(_endNodeCenter.x() + bbEnd.xMax(), _endNodeCenter.y(), _endNodeCenter.z()));
		(*_vertices)[1].set(osg::Vec3(_endNodeCenter.x(), _endNodeCenter.y(), _endNodeCenter.z() - bbEnd.yMax()/2/*+ bbEnd.yMin()*/ ));
		(*_vertices)[2].set(osg::Vec3(_endNodeCenter.x(), _endNodeCenter.y(), _endNodeCenter.z() + bbEnd.yMax()/2));

		_lineGeom->setVertexArray(_vertices);
		_lineGeom->setPrimitiveSet(0,new osg::DrawArrays(osg::PrimitiveSet::POLYGON,0,_vertices->getNumElements()));
			// set the colors a
		osg::Vec4Array* colors = new osg::Vec4Array;
		colors->push_back(osg::Vec4(0.0f,0.0f,0.0f,0.2f)); //black
		_lineGeom->setColorArray(colors);
		_lineGeom->setColorBinding(osg::Geometry::BIND_OVERALL);
		osg::StateSet* lineState = _lineGeom->getOrCreateStateSet();
		osg::LineWidth* lineWidth = new osg::LineWidth(2.0);
		lineState->setAttribute(lineWidth);

		// make transparent
		osg::StateSet* edgeFillingStateSet = _lineGeom->getOrCreateStateSet();
		osg::BlendFunc* bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
		edgeFillingStateSet->setAttributeAndModes(bf);
		edgeFillingStateSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

		this->addDrawable(_lineGeom);
	}



}