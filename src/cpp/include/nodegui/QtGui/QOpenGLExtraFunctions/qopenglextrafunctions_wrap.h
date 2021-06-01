#pragma once

#include <napi.h>

#include <QOpenGLExtraFunctions>

#include "Extras/Export/export.h"
#include "core/Component/component_macro.h"

class DLL_EXPORT QOpenGLExtraFunctionsWrap
    : public Napi::ObjectWrap<QOpenGLExtraFunctionsWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION
 private:
  QOpenGLExtraFunctions* instance;
  bool isOwnsInstance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QOpenGLExtraFunctionsWrap(const Napi::CallbackInfo& info);
  ~QOpenGLExtraFunctionsWrap();
  QOpenGLExtraFunctions* getInternalInstance();
  // Wrapped methods
  Napi::Value glBindBuffer(const Napi::CallbackInfo& info);
  Napi::Value glBindVertexArray(const Napi::CallbackInfo& info);
  Napi::Value glBufferData(const Napi::CallbackInfo& info);
  Napi::Value glClear(const Napi::CallbackInfo& info);
  Napi::Value glClearColor(const Napi::CallbackInfo& info);
  Napi::Value glCullFace(const Napi::CallbackInfo& info);
  Napi::Value glDepthFunc(const Napi::CallbackInfo& info);
  Napi::Value glDisable(const Napi::CallbackInfo& info);
  Napi::Value glDrawArrays(const Napi::CallbackInfo& info);
  Napi::Value glEnable(const Napi::CallbackInfo& info);
  Napi::Value glEnableVertexAttribArray(const Napi::CallbackInfo& info);
  Napi::Value glFrontFace(const Napi::CallbackInfo& info);
  Napi::Value glGenBuffer(const Napi::CallbackInfo& info);
  Napi::Value glGenVertexArray(const Napi::CallbackInfo& info);
  Napi::Value glGetString(const Napi::CallbackInfo& info);
  Napi::Value glUseProgram(const Napi::CallbackInfo& info);
  Napi::Value glVertexAttribPointer(const Napi::CallbackInfo& info);
  Napi::Value initializeOpenGLFunctions(const Napi::CallbackInfo& info);
};
