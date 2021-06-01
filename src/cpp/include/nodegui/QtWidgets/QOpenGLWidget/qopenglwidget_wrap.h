#pragma once

#include <napi.h>

#include <QPointer>

#include "Extras/Export/export.h"
#include "QtWidgets/QWidget/qwidget_macro.h"
#include "nopenglwidget.hpp"

class DLL_EXPORT QOpenGLWidgetWrap
    : public Napi::ObjectWrap<QOpenGLWidgetWrap> {
  QWIDGET_WRAPPED_METHODS_DECLARATION
 private:
  QPointer<NOpenGLWidget> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLWidgetWrap(const Napi::CallbackInfo& info);
  ~QOpenGLWidgetWrap();
  NOpenGLWidget* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods

  // Napi::Value setSelection(const Napi::CallbackInfo& info);
  // Napi::Value selectionStart(const Napi::CallbackInfo& info);
  // Napi::Value setBuddy(const Napi::CallbackInfo& info);
  // Napi::Value clear(const Napi::CallbackInfo& info);
  // Napi::Value setMovie(const Napi::CallbackInfo& info);
  // Napi::Value setNumDouble(const Napi::CallbackInfo& info);
  // Napi::Value setNumInt(const Napi::CallbackInfo& info);
  // Napi::Value setPicture(const Napi::CallbackInfo& info);
  // Napi::Value setPixmap(const Napi::CallbackInfo& info);
};
