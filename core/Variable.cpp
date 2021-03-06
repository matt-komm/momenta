#include "Variable.hpp"

Variable::Variable(std::string name, Node* owner):
    _name(name),
    _owner(owner),
    _parent(0)
{
}

Variable::~Variable()
{
}

const Variable* Variable::getParent() const
{
    return _parent;
}

bool Variable::hasParent() const
{
    return _parent != 0;
}

void Variable::addChild(Variable* variable)
{
    //std::cout<<"set parent of '"<<variable->getName()<<" "<<variable<<"'"<<std::endl;
    variable->_parent=this;
    //set the size here - keep in mind: upon creation as const input variable -> size cannot be set
    variable->setSize(this->size());
    //std::cout<<"variable: "<<_name<<" -> addChild:"<<variable->getName()<<std::endl;
    _children.push_back(variable);
}

void Variable::updateChildren()
{
    for (unsigned int ichild = 0; ichild < _children.size(); ++ichild)
    {
        //std::cout<<"variable: "<<_name<<" -> update:"<<_children[ichild]->getName()<<std::endl;
        for (unsigned int index = 0; index<this->size(); ++index)
        {
            _children[ichild]->value(index)=this->value(index);
        }
    }
}

