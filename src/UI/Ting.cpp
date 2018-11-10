//
//  Ting.cpp
//  sdl test
//
//  Created by Richard on 23/08/2018.
//  Copyright © 2018 Richard. All rights reserved.
//

#include "Ting.hpp"
#include <vector>
#include <assert.h>
typedef unsigned int pos;

template<class T>
class fbuffer{
    T * _buffer;
    int _pos;
    int _length;
    char * _get(int offset){
        this->_buffer[offset];
    }
    T get(){
        return this->_buffer[this->pos];
    }
    int push(){
        if(this->_pos++ > this->_length)
            this->_pos = 0;
        this->_buffer[this->_pos];
    }
    fbuffer(unsigned int len){
        this->_buffer = new char[len];
        this->_pos = 0;
        this->_length = len;
    }
    ~fbuffer(){
        delete [] this->buffer;
    }
};

#define _WINDOW_DIRTY 0x1
#define _WINDOW_HIDDEN 0x2
#define _WINDOW_MINIMISED 0x4
#define _WINDOW_SOMETHING 0x8
enum e_window_flags{
    WINDOW_DIRTY = 0x1,
    WINDOW_HIDDEN = 0x2,
    WINDOW_MINIMISED = 0x4,
};
struct s_window{
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;
    unsigned int flags;
    unsigned int depth;
};
#define IS_SET(x, mask) ((x & mask) == mask)
#define FLAG_SET(x, mask) (x |= mask)
#define FLAG_REMOVE(x, mask) (x &= ~mask)

typedef int test;
class c_window : public s_window{
    //s_window _window;
    std::vector<c_window *> _children;
public:
    
    void setFlag(e_window_flags e){
        //e
    }
    
    c_window * addChild(c_window * window){
        this->_children.push_back(window);
        return window;
    }
    
    virtual int onShow();
    virtual int onHide();
    virtual int onCreate();
    virtual int onDestroy();
    
    virtual void render(void * tex){
        for(int i = 0; i < this->_children.size(); ++i){
            assert(this->_children[i] == nullptr);
            if(IS_SET(this->_children[i]->flags, e_window_flags::WINDOW_DIRTY))
                continue;
            this->_children[i]->render(tex);
        }
    }
    
    s_window * getPos(){
        return (s_window*)this;
    }
    
    void setPos(unsigned int x, unsigned int y){
        this->x = x;
        this->y = y;
    }
    
    c_window();
    
    c_window(
             unsigned int x,
             unsigned int y,
             unsigned int w,
             unsigned int h){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
    
    ~c_window(){
        for(int i =0; i < this->_children.size(); ++i)
            delete this->_children[i];
    }
    
};

class c_control: public c_window{
public:
    c_control(
              unsigned int x, unsigned int y,
              unsigned int w, unsigned int h)
        : c_window(x, y, w, h){
        
    }
    ~c_control();
};

class c_control_text: public c_control{
private:
    const char * _string;
    size_t _length;
public:
    void render(void * text){
        
    }
    void setText(const char * string){
        this->_string = string;
        this->_length = strlen(string);
    }
    const char * getText(){
        return this->_string;
    }
    const char getLength(){
        return this->_length;
    }
    c_control_text(
                   char const * str,
                   pos x,
                   pos y,
                   pos w,
                   pos h)
        : c_control(x, y, w ,h){
        this->_string = str;
    }
};

class c_control_scrollable{
    
    
};

class c_control_text_multiline : public c_control_text{
    
};

class my_control_window: c_window{
    
    my_control_window(){
        this->addChild(new c_control_text("text", 100, 20, 0, 0));
    }
};
