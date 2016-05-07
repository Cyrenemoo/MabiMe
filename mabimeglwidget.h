#ifndef MABIMEGLWIDGET_H
#define MABIMEGLWIDGET_H

#include <QGLWidget>
#include <QList>
#include <QPoint>

#include "PackReader/pmgreader.h"

struct Rotation {
    int pitch = 0, yaw = 0, roll = 0;
};

struct CameraInfo {
    float x = 0, y = 40, zoom = -170;
    Rotation rotation;
};

class MabiMeGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MabiMeGLWidget(QWidget *parent = 0);
    QList<PMG::Mesh*> meshes = QList<PMG::Mesh*>();
    CameraInfo getCameraInfo();
private:
    CameraInfo camera;
    QPoint drag;
    QPointF oldCameraPos = QPointF(0, 40);
    Rotation oldCameraRotation;
    bool isLeftDragging = false;
    bool isRightDragging = false;
    void wheelEvent(QWheelEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void CheckError(QString error);
    float ti = 0 ;
    PFNGLCREATEPROGRAMPROC           glCreateProgram;
    PFNGLCREATESHADERPROC            glCreateShader;
    PFNGLSHADERSOURCEPROC            glShaderSource;
    PFNGLCOMPILESHADERPROC           glCompileShader;
    PFNGLATTACHSHADERPROC            glAttachShader;
    PFNGLGETSHADERINFOLOGPROC        glGetShaderInfoLog;
    PFNGLLINKPROGRAMPROC             glLinkProgram;
    PFNGLUSEPROGRAMPROC              glUseProgram;
    PFNGLGETUNIFORMLOCATIONPROC      glGetUniformLocation;
    PFNGLUNIFORM1IPROC               glUniform1i;
    PFNGLUNIFORM1IVPROC              glUniform1iv;
    PFNGLUNIFORM1FPROC               glUniform1f;
    PFNGLUNIFORM2FPROC               glUniform2f;
    PFNGLUNIFORM3FPROC               glUniform3f;
    PFNGLUNIFORM4FPROC               glUniform4f;
    PFNGLUNIFORM4FVPROC              glUniform4fv;
    PFNGLBINDATTRIBLOCATIONPROC      glBindAttribLocation;
    PFNGLGETPROGRAMINFOLOGPROC       glGetProgramInfoLog;
    PFNGLVERTEXATTRIBPOINTERPROC     glVertexAttribPointer;
    PFNGLGETATTRIBLOCATIONPROC       glGetAttribLocation;
    PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
    PFNGLGENFRAMEBUFFERSEXTPROC      glGenFramebuffers;
    PFNGLBINDFRAMEBUFFEREXTPROC      glBindFramebuffer;
    PFNGLFRAMEBUFFERTEXTURE2DPROC    glFramebufferTexture2D;
    PFNGLBLENDFUNCSEPARATEPROC       glBlendFuncSeparate;
    PFNGLBINDBUFFERPROC              glBindBuffer;
    PFNGLBUFFERDATAPROC              glBufferData;
    PFNGLGENBUFFERSPROC              glGenBuffers;
    PFNGLACTIVETEXTUREPROC           glActiveTexture;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void renderPMGMesh(PMG::Mesh mesh);
signals:
    void cameraChange(CameraInfo camera);
public slots:
};

#endif // MABIMEGLWIDGET_H
