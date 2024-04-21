#ifndef _CONTENT_H_
#define _CONTENT_H_

#include <GL/glew.h>

#include "renderer.h"

class content
{
public:
	renderer r;

	content();

	void init();
	void Update();
	void Render();

	~content();
};

#endif