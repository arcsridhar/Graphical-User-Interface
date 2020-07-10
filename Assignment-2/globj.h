#ifndef GLOBJ_H
#define GLOBJ_H

#include <QGLWidget>

class GLobj : public QGLWidget
{
    Q_OBJECT

public:
    GLobj(QWidget *parent = 0);
    ~GLobj();


protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void ngon(int n);

};
#endif // GLOBJ_H

