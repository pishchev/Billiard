#include "meshloader.h"
#include <QFile>
#include <vector>
#include <array>

MeshLoader::MeshLoader()
{
    Object loadMesh(std::string filename);
}

std::vector<Vertex> MeshLoader::loadMesh(const std::string& filename)
{
    QFile objFile(filename.data());

    objFile.open(QIODevice::ReadOnly);

    QTextStream input(&objFile);

    std::vector<std::array<GLfloat ,3>> vertCont;
    std::vector<std::array<GLfloat ,3>> normCont;
    std::vector<std::array<GLfloat ,2>> textCont;

    Object obj;

    while(!input.atEnd())
    {
        QString string = input.readLine();
        QStringList tokens = string.split(" ");


        if (tokens[0] == "v")
        {
            std::array<GLfloat ,3> tmp;
            tmp[0] = tokens[1].toFloat();
            tmp[1] = tokens[2].toFloat();
            tmp[2] = tokens[3].toFloat();
            vertCont.push_back(tmp);
            continue;
        }
        if (tokens[0] == "vt")
        {
            std::array<GLfloat ,2> tmp;
            tmp[0] = tokens[1].toFloat();
            tmp[1] = tokens[2].toFloat();
            textCont.push_back(tmp);
            continue;
        }
        if (tokens[0] == "vn")
        {
            std::array<GLfloat ,3> tmp;
            tmp[0] = tokens[1].toFloat();
            tmp[1] = tokens[2].toFloat();
            tmp[2] = tokens[3].toFloat();
            normCont.push_back(tmp);
            continue;
        }

        if (tokens[0] == "f")
        {
           for(size_t i=1;i<4;++i)
           {
               QStringList index = tokens[i].split("/");
               Vertex A;
               A.vertex = vertCont[index[0].toLong()-1];
               A.texCoord = textCont[index[1].toLong()-1];
               A.normal = normCont[index[2].toLong()-1];
               obj.vertexs.push_back(A);
           }
            continue;
        }

    }
    objFile.close();

    return obj.vertexs;
}
