#ifndef PMGREADER_H
#define PMGREADER_H

#include <QByteArray>
#include <QtOpenGL>
#include <GL/gl.h>

namespace PMG {
    #pragma pack(1)
    struct FileHeader {
        char magic[4];
        short version;
        int headSize;
        char meshName[128];
        int meshType;
    };
    #pragma pack(1)
    struct Skin {
        int vertexID = 0;
        int a = 0;
        float boneWeight = 1.0;
        int b = 1;
    };
    #pragma pack(1)
    struct Vertex {
        float x, y, z;
        float nx, ny, nz;
        unsigned char r,g,b,a;
        float u,v;
        Skin skin;
        int globalID = 0;
    };
    #pragma pack(0)
    struct ShaderVertex {
        float x,y,z, weight;
    };

    struct Mesh {
        int size;
        QString boneName, boneName2, statName, normalName, meshName, textureName, colourMap;
        QStringList boneNames;
        char parts2Length;
        int count;
        QMatrix4x4 minorMatrix, majorMatrix;
        int partNo               = 0;
        int faceVertexCount      = 0;
        int faceCount            = 0;
        int stripFaceVertexCount = 0;
        int stripFaceCount       = 0;
        int vertexCount          = 0;
        int skinCount            = 0;
        QList<short> vertexList = QList<short>();
        QList<short> stripVertexList = QList<short>();
        QList<Vertex*> vertices = QList<Vertex*>();
        QList<int> globalVertices = QList<int>();
        GLfloat *cleanVertices;
        GLfloat *cleanColours;
        GLfloat *cleanNormals;
        GLfloat *cleanTextureCoords;
        GLfloat *cleanBoneWeights;
        GLint *cleanBoneIDs;
        GLfloat *shaderVertices;
        int cleanVertexCount;
        QList<Skin*> skins = QList<Skin*>();
    };
}

class PMGReader
{
private:
    PMG::FileHeader header;
    bool hasLoaded = false;
    int appendVertex(PMG::Vertex *v);
public:
    void freePMG();
    QStringList textures;
    QList<PMG::Vertex*> vertices = QList<PMG::Vertex*>();
    QList<PMG::Mesh*> meshes;
    PMGReader();
    ~PMGReader();
    bool loadPMG(QByteArray stream);
};

#endif // PMGREADER_H
