#pragma once

#include <QOpenGLWidget>

#include "Extras/Export/export.h"
#include "QtWidgets/QFrame/qframe_macro.h"
#include "QtWidgets/QWidget/qwidget_macro.h"
#include "core/NodeWidget/nodewidget.h"

class DLL_EXPORT NOpenGLWidget : public QOpenGLWidget, public NodeWidget {
  Q_OBJECT
  NODEWIDGET_IMPLEMENTATIONS(QOpenGLWidget)
 public:
  using QOpenGLWidget::QOpenGLWidget;  // inherit all constructors of QOpenGLWidget

  void connectSignalsToEventEmitter() {
    QWIDGET_SIGNALS
  //   QObject::connect(this, &QLabel::linkActivated, [=](const QString& link) {
  //     Napi::Env env = this->emitOnNode.Env();
  //     Napi::HandleScope scope(env);
  //     this->emitOnNode.Call({Napi::String::New(env, "linkActivated"),
  //                            Napi::String::New(env, link.toStdString())});
  //   });
  //   QObject::connect(this, &QLabel::linkHovered, [=](const QString& link) {
  //     Napi::Env env = this->emitOnNode.Env();
  //     Napi::HandleScope scope(env);
  //     this->emitOnNode.Call({Napi::String::New(env, "linkHovered"),
  //                            Napi::String::New(env, link.toStdString())});
  //   });
  }
 protected:
  virtual void initializeGL() override {
    Napi::Env env = this->emitOnNode.Env();
    Napi::HandleScope scope(env);
    this->emitOnNode.Call({Napi::String::New(env, "initializeGL")});
  }

  virtual void paintGL() override {
    Napi::Env env = this->emitOnNode.Env();
    Napi::HandleScope scope(env);
    this->emitOnNode.Call({Napi::String::New(env, "paintGL")});
  }

  virtual void resizeGL(int w, int h) override {
    Napi::Env env = this->emitOnNode.Env();
    Napi::HandleScope scope(env);
    this->emitOnNode.Call({Napi::String::New(env, "resizeGL"),
                           Napi::Number::New(env, w),
                           Napi::Number::New(env, h)});
  }
};
