#include <osg/EdgeUpdateCallback>

using namespace osg;

void EdgeUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
	if (node->getDataVariance() == osg::Object::DYNAMIC)
	{
		osg::Edge* theEdge = dynamic_cast<osg::Edge*>(node);
		theEdge->EdgeUpdate();
	}
	traverse(node,nv);
}
