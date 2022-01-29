#include "Application.h"
#include <assert.h>


int main()
{

	Application application;
	if (!application.Create(1280, 720))
	{
		assert("this shouldn't ever happen");
	}

	return 0;
}