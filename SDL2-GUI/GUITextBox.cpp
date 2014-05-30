#include"GUITextBox.h"

GUITextBox::GUITextBox(){
	m_pos.x = 0;
	m_pos.y = 0;
	m_width = 0;
	m_height = 0;
}

GUITextBox::~GUITextBox(){

}

void GUITextBox::draw(){
	
	m_view->renderTextStash( m_text,  m_pos.x , m_pos.y , 32 );
	m_view->renderText( m_textVAO , m_pos.x, m_pos.y, 32 , m_text.size() );

	std::vector<Element*>::iterator itr;
	itr = m_children.begin();

	for(; itr != m_children.end(); itr++){
		itr[0]->draw();
	}
}

bool GUITextBox::isOver(int x, int y){
	if( y > (m_screenPos.y) && y < (m_screenPos.y + m_height) &&
		x > (m_screenPos.x) && x < (m_screenPos.x + m_width) ){
			return true;
	}
	return false;
}

void GUITextBox::onClick(){
	std::vector<Element*>::iterator itr;
	itr = m_children.begin();

	for(; itr != m_children.end(); itr++){
		itr[0]->onClick();
	}
}

void GUITextBox::onMouseMotion(SDL_Event* ev){
	std::vector<Element*>::iterator itr;
	itr = m_children.begin();

	for(; itr != m_children.end(); itr++){
		itr[0]->onMouseMotion(ev);
	}
}

void GUITextBox::onMouseButton(SDL_Event* ev, GUIEvent* clicked){
	std::vector<Element*>::iterator itr;
	itr = m_children.begin();

	for(; itr != m_children.end(); itr++){
		itr[0]->onMouseButton(ev, clicked);
	}
}