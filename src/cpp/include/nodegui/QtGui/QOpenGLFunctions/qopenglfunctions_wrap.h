#pragma once

#include <napi.h>

#include <QOpenGLFunctions>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QOpenGLFunctionsWrap : public Napi::ObjectWrap<QOpenGLFunctionsWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QOpenGLFunctions* instance;
  bool isOwnsInstance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLFunctionsWrap(const Napi::CallbackInfo& info);
  ~QOpenGLFunctionsWrap();
  QOpenGLFunctions* getInternalInstance();
  // Wrapped methods
  Napi::Value glBindBuffer(const Napi::CallbackInfo& info);
  Napi::Value glClear(const Napi::CallbackInfo& info);
  Napi::Value glClearColor(const Napi::CallbackInfo& info);
  Napi::Value glCullFace(const Napi::CallbackInfo& info);
  Napi::Value glDepthFunc(const Napi::CallbackInfo& info);
  Napi::Value glDisable(const Napi::CallbackInfo& info);
  Napi::Value glDrawArrays(const Napi::CallbackInfo& info);
  Napi::Value glEnable(const Napi::CallbackInfo& info);
  Napi::Value glFrontFace(const Napi::CallbackInfo& info);
  Napi::Value glGetString(const Napi::CallbackInfo& info);
  Napi::Value glUseProgram(const Napi::CallbackInfo& info);
  Napi::Value initializeOpenGLFunctions(const Napi::CallbackInfo& info);
};
