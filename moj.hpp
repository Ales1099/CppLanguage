#include <iostream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "math_3D.h"

#define INCORRECTLY 0
#define ENOF        3435973836

typedef unsigned int UNIT;

namespace emn {
namespace mesh {

	class MeshObj
	{
	private:
		std::vector<vector3D> url_v;
		std::vector<vector3D> url_vt;
		std::vector<vector3D> url_vn;
		std::vector<unsigned int> mass_v, mass_vt, mass_vn;
		const char * filename;
	public:

		GLuint VBO;
		GLuint IBO;

		UNIT sizeVBO;
		UNIT sizeIBO;

		MeshObj();
		MeshObj(const char * __filename);
		~MeshObj();
		void readFileObj();
		//int read_file();
		//void createBufferVer();
		//void createBufferInd();
		void print();
	private:
		inline void createVBO();
		inline void createIBO();
	};

}}