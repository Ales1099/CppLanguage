#include "moj.hpp"

namespace emn {
namespace mesh {

	MeshObj::MeshObj()
	{
		//filename = (const char*)std::malloc(1000*sizeof(const char));
	}

	MeshObj::MeshObj(const char * __filename) 
	{
		filename = __filename;
		readFileObj();
		createVBO();
		createIBO();
	}

	MeshObj::~MeshObj()
	{
		//std::free(filename);
	}

	void MeshObj::readFileObj()
	{
		FILE * file = fopen(filename, "rb");

		if (file == NULL)
		{
			std::cout << "fatal erro :: " << filename << "is not find" << std::endl;
			return;
		}

		unsigned int arr_v[4];
		unsigned int arr_vt[4];
		unsigned int arr_vn[4];

		while (true)
		{
			char * ptr = (char*)malloc(100 * sizeof(char));
			int erro = fscanf(file, "%s", ptr);

			if (erro == EOF) break;

			
			if (std::strcmp(ptr, "v") == 0)
			{
				vector3D help;
				fscanf(file, " %f %f %f\n", &help.x, &help.y, &help.z);
				url_v.push_back(help);
			}

			if (std::strcmp(ptr, "vt") == 0)
			{
				vector3D help;
				fscanf(file, " %f %f %f\n", &help.x, &help.y, &help.z);
				url_vt.push_back(help);
			}
			
			if (std::strcmp(ptr, "vn") == 0)
			{
				vector3D help;
				fscanf(file, " %f %f %f\n", &help.x, &help.y, &help.z);
		    	url_vn.push_back(help);
			}

			if (std::strcmp(ptr, "f") == 0)
		    {   
				long long int t = ftell(file);
            
				int ptr = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d",
					&arr_v[0], &arr_vt[0], &arr_vn[0],
					&arr_v[1], &arr_vt[1], &arr_vn[1],
					&arr_v[2], &arr_vt[2], &arr_vn[2],
					&arr_v[3], &arr_vt[3], &arr_vn[3]);

				if (ptr == 12)
				{
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);
					mass_v.push_back(arr_v[3]);

					mass_vt.push_back(arr_vt[0]);
					mass_vt.push_back(arr_vt[1]);
					mass_vt.push_back(arr_vt[2]);
					mass_vt.push_back(arr_vt[3]);

					mass_vn.push_back(arr_vn[0]);
					mass_vn.push_back(arr_vn[1]);
					mass_vn.push_back(arr_vn[2]);
					mass_vn.push_back(arr_vn[3]);
					continue;
				}
				else
				{
					fseek(file, (t), SEEK_SET);
				}

				ptr = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d",
					&arr_v[0], &arr_vt[0], &arr_vn[0],
					&arr_v[1], &arr_vt[1], &arr_vn[1],
					&arr_v[2], &arr_vt[2], &arr_vn[2]);

				if (ptr == 9)
				{
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);

					mass_vt.push_back(arr_vt[0]);
					mass_vt.push_back(arr_vt[1]);
					mass_vt.push_back(arr_vt[2]);

					mass_vn.push_back(arr_vn[0]);
					mass_vn.push_back(arr_vn[1]);
					mass_vn.push_back(arr_vn[2]);
					continue;
				}
				else
				{
					fseek(file, t, SEEK_SET);
				}

				ptr = fscanf(file, "%d//%d %d//%d %d//%d %d//%d",
					&arr_v[0], &arr_vn[0],
					&arr_v[1], &arr_vn[1],
					&arr_v[2], &arr_vn[2],
					&arr_v[3], &arr_vn[3]);

				if (ptr == 8)
				{
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);
					mass_v.push_back(arr_v[3]);

					mass_vn.push_back(arr_vn[0]);
					mass_vn.push_back(arr_vn[1]);
					mass_vn.push_back(arr_vn[2]);
					mass_vn.push_back(arr_vn[3]);
					continue;
				}
				else
				{
					fseek(file, (t), SEEK_SET);
				}

				ptr = fscanf(file, "%d//%d %d//%d %d//%d",
					&arr_v[0], &arr_vn[0],
					&arr_v[1], &arr_vn[1],
					&arr_v[2], &arr_vn[2]);

				if (ptr == 8)
				{
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);

					mass_vn.push_back(arr_vn[0]);
					mass_vn.push_back(arr_vn[1]);
					mass_vn.push_back(arr_vn[2]);
					
					continue;
				}
				else
				{
					fseek(file, t, SEEK_SET);
				}

				ptr = fscanf(file, "%d %d %d %d",
					&arr_v[0], &arr_v[1], &arr_v[2], &arr_v[3]);

				if (ptr == 4)
				{
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);
					mass_v.push_back(arr_v[3]);
					continue;
				}
				else
				{
					fseek(file, (t), SEEK_SET);
				}

				ptr = fscanf(file, "%d %d %d",
					&arr_v[0], &arr_v[1], &arr_v[2]);

				if (ptr == 3)
				{
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);

					continue;
				}
				else
				{
					fseek(file, t, SEEK_SET);
				}

				ptr = fscanf(file, "%d/%d %d/%d %d/%d %d/%d",
					&arr_v[0], &arr_vt[0], 
					&arr_v[1], &arr_vt[1],
					&arr_v[2], &arr_vt[2],
					&arr_v[3], &arr_vt[3]);

				if (ptr == 8) {
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);
					mass_v.push_back(arr_v[3]);

					mass_vt.push_back(arr_vt[0]);
					mass_vt.push_back(arr_vt[1]);
					mass_vt.push_back(arr_vt[2]);
					mass_vt.push_back(arr_vt[3]);
					continue;
				}
				else
				{
					fseek(file, (t), SEEK_SET);
				}

				ptr = fscanf(file, "%d/%d %d/%d %d/%d",
					&arr_v[0], &arr_vt[0],
					&arr_v[1], &arr_vt[1],
					&arr_v[2], &arr_vt[2]);

				if (ptr == 6)
				{
					mass_v.push_back(arr_v[0]);
					mass_v.push_back(arr_v[1]);
					mass_v.push_back(arr_v[2]);

					mass_vt.push_back(arr_vt[0]);
					mass_vt.push_back(arr_vt[1]);
					mass_vt.push_back(arr_vt[2]);

					continue;
				}
				else
				{
					fseek(file, t, SEEK_SET);
				}
			}
			std::free(ptr);
		}
		fclose(file);
	}

	void MeshObj::print()
	{
		std::cout << "v" << std::endl;

	    for (int i = 0; i < mass_v.size(); i++)
		{
			std::cout << mass_v[i] <<" ";
		}

		std::cout << std::endl;
		std::cout << "vt" << std::endl;

		for (int i = 0; i < mass_vt.size(); ++i)
		{
			std::cout << mass_vt[i] << " ";
		}

		std::cout << std::endl;
		std::cout << "vn" << std::endl;

		for (int i = 0; i < mass_vn.size(); ++i)
		{
			std::cout << mass_vn[i] << " ";
		}
	}

	inline void MeshObj::createVBO()
	{
		vector3D * vectors = new vector3D[url_v.size()];
	//	vectors[0] = vector3D(-1.0f, -1.0f, 0.5773f);
	//	vectors[1] = vector3D(0.0f, -1.0f, -1.15475f);
	//	vectors[2] = vector3D(1.0f, -1.0f, 0.5773f);
	//	vectors[3] = vector3D(0.0f, 1.0f, 0.0f);

		for (int i = 0; i < url_v.size(); ++i)
		{
			*(vectors + i) = vector3D(url_v[i].x,url_v[i].y,url_v[i].z);
		}

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, url_v.size() * sizeof(*vectors), vectors, GL_STATIC_DRAW);
	}

	inline void MeshObj::createIBO()
	{
		UNIT * index = new UNIT[mass_v.size()];
		//0,3,1,
		//1,3,2,
		//2,3,0,
		//0,2,1
		//};

		for (int i = 0; i < mass_v.size(); ++i)
		{
			*(index + i) = mass_v[i] - 1;
		}

		sizeIBO = mass_v.size();

		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeIBO * sizeof(*index), index, GL_STATIC_DRAW);
	}

}}