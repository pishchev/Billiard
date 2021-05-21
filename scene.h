#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLShaderProgram>
#include <QOpenGLExtraFunctions>
#include <QOpenGLFunctions_3_0>
#include <QColorDialog>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QLabel>
#include <QTime>
#include <QOpenGLTexture>
#include "coub.h"
#include "objectmodel.h"
#include "normals.h"
#include "object.h"
#include "sourcelight.h"
#include "sphere.h"
#include "meshloader.h"
#include "surface.h"
#include "camera.h"
#include "keyboard.h"
#include "mouse.h"
#include "quadMesh.h"
#include "ball.h"
#include "triangle.h"
#include "arrow.h"
#include "powerscale.h"
#include "gettingballs.h"

class Scene : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
void initializeGL() override;
void initProgram();
void initShadersParam();
void initObject();

void paintGL() override;
void lightUniforms();

void setLightCoefs(std::vector<int> vec);

void SetFilterMode(int filterMode);
void SetWrapMode(int wrapMode);

void Filtering(const Object& o, int i);

void keyPressEvent(QKeyEvent* event) override;
void keyReleaseEvent(QKeyEvent* event) override;
void keyEvent();

void mouseMoveEvent(QMouseEvent *event) override;
void mouseEvent();

void initShadowBuffers();

void goals_check();

void createShadowMap();

Scene(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags()):QOpenGLWidget(parent,f), timer(new QTimer(this)){}

~Scene(){}

private:

BallsPool ballsPool;
Arrow arrow;
Powerscale powerScale;
GettingBalls gBalls;

std::vector<Object> table;
std::vector<Object> lamps;
std::vector<Object> walls;

std::vector<Object> gettingBalls;
std::vector<Object> balls_goal;
float balls_goal_rad = 1.0f;

std::vector<LightObject> lights;



Camera camera;

LightFactors coefs;
bool test = false;
KeyBoard keys;
Mouse mouse;

GLint m_norAttr = 0;
GLint m_posAttr = 0;

GLint m_trMatrix = 0;
GLint m_matrixUniform = 0;

unsigned int depthMapFBO[4];
const unsigned int SHADOW_WIDTH = 1920, SHADOW_HEIGHT = 1920;
GLuint depthMap[4];

int m_minFilterMode  =0 ;
int m_magFilterMode =0 ;
int m_useAniso =0 ;
int m_wrapMode =0 ;

QMatrix4x4 lightSpaceMatrix[4];

QOpenGLFunctions *f = nullptr;
QOpenGLShaderProgram *m_program = nullptr;

QOpenGLShaderProgram *m_programDepth = nullptr;

QOpenGLShaderProgram *m_programDebugShadows = nullptr;

int m_frame = 0;
QTimer* timer = nullptr;
};

#endif // SCENE_H
